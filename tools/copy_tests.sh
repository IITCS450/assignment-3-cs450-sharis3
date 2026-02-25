#!/usr/bin/env bash
set -euo pipefail
if [[ $# -ne 1 ]]; then
  echo "Usage: $0 <A2-setpriority|A3-lottery|A4-null-protect|A5-uthreads|A6-filesystem>"
  exit 1
fi
ASG="$1"
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
XV6="$ROOT/xv6"
SRC="$ROOT/user"
if [[ ! -d "$XV6" ]]; then
  echo "ERROR: xv6/ not found. Populate xv6 first."
  exit 1
fi
cp -v "$SRC"/*.c "$XV6"/
cp -v "$SRC"/*.h "$XV6"/ 2>/dev/null || true
echo "Copied tests/scaffolds for $ASG into xv6/"
echo "Reminder: add corresponding _binary names to xv6/Makefile UPROGS"
