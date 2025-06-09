#!/bin/bash
set -e

usage() {
    echo "Usage: $0 <block-hash> [remote-name]"
    exit 1
}

BLOCK_HASH="$1"
REMOTE="${2:-origin}"

[ -n "$BLOCK_HASH" ] || usage

WORKDIR="$(dirname "$0")/.."
cd "$WORKDIR"

# Attempt to fetch raw block hex from blockbook API
API_URL="https://blockbook.fiveg.cash/api/v2/rawblock/$BLOCK_HASH"

if ! which curl >/dev/null 2>&1 ; then
    echo "curl is required" >&2
    exit 1
fi

HEX=$(curl -fsSL "$API_URL" 2>/dev/null | grep -o '"rawblock"\s*:\s*"[0-9a-fA-F]*"' | sed -E 's/.*"([0-9a-fA-F]+)"/\1/')

if [ -z "$HEX" ]; then
    echo "Failed to fetch block data from $API_URL" >&2
    exit 1
fi

mkdir -p resources/testdata

BIN_PATH="resources/testdata/vgc_block.bin"

# Convert hex to binary
printf "%s" "$HEX" | xxd -r -p > "$BIN_PATH"

echo "Saved block to $BIN_PATH"

# Register the file in qrc if necessary
QRC_FILE="resources/testdata/testdata.qrc"
if ! grep -q "vgc_block.bin" "$QRC_FILE"; then
    sed -i '/bch_block_833705.bin/a\        <file>vgc_block.bin</file>' "$QRC_FILE"
    echo "Updated $QRC_FILE"
fi

# Stage and commit

git add "$BIN_PATH" "$QRC_FILE"

if git diff --cached --quiet; then
    echo "Nothing to commit"
else
    git commit -m "Add VGC test block $BLOCK_HASH"
    git push "$REMOTE" HEAD
fi

