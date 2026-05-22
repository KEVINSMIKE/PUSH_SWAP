#!/bin/bash
ARG="$@"
OPS=$(./push_swap $ARG)
if [ -z "$OPS" ]; then
    echo "OK (déjà trié ou vide)"
    exit 0
fi
# Simuler les opérations
echo "$OPS" | head -3
echo "Ops: $(echo "$OPS" | wc -l)"
