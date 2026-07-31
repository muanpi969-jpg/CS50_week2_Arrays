# Readability

## What it does

`readability.c` counts letters, words, and sentences, then uses the Coleman–Liau index to estimate the U.S. school grade level needed to understand a passage.

## Compile

```bash
clang readability.c -o readability -lcs50 -lm
```

## Use

```bash
./readability
```

Paste or type a passage when prompted.
