# 20261120 batch driver -- analysis drop for review

This tree is the review payload of the 20261120 batch: 58 analysed products (31 CLR/IL, 19 native PE, 8 non-PE).
It is pushed to the review branch only; nothing here touches the default branch.

## 0. Scope and manifest

Driver dir: analysis/20261120-batch-driver/. Files come from the frozen local analysis run
(R1 for CLR, R1N for native); no analysis is re-run by the push itself.
Origins (the inspected binaries) are never uploaded: the gate rejects any
payload whose sha256 equals an origin hash.

## 1. How to run

Two mutually exclusive modes; pick exactly one:

(a) products already on disk (reuse, no re-analysis):

      python tool/run_batch.py --auto --manifest read-test-waiting.csv --source-root dl

(b) new items or missing products (re-run analysis, about +160 min):

      python tool/run_batch.py --auto --manifest read-test-waiting.csv --source-root dl --force-analyze

RUNMODE=a is the mode used for this round.

## 2. Reuse semantics

An item is reused when its product files exist and the recomputed
product_sha256 equals the recorded one. product_sha256 is defined per item:
its product files sorted by basename, concatenated as name=sha256;, hashed.
A missing product is ANALYZE-MISSING and exits 2 unless --force-analyze.

## 3. Upload gate

Every push goes through tool/check_upload.py with explicit --out and
--allowlist-out (no defaults, fail-closed). findings>0 means exit 1 and no
allowlist, so publish.py has nothing to push. The staging tree is audited
file by file: extension allowlist, size caps, leak rules, origin hashes,
and the fixed deviation sentence in every analysis markdown.

## 4. Push and readback

publish.py uses the Git Data API only (blobs -> trees -> commits -> refs).
It refuses any write to refs/heads/main, any force flag, and any ref
deletion. Non fast-forward (422) stops the run. Afterwards it reads the
branch ref, the tree and 5 sampled files back and compares sha256.

## 5. State and increments

out/state.json records round, branch, last_commit and one entry per item.
Re-running with the same state is idempotent (skip=58, pushed=0).
--since <head> is the stateless mode and is mutually exclusive with --state.

## 6. Deviation and limits

This drop deviates from the repository AGENTS instructions on purpose:
it is a binary-analysis payload, not source code, and the fixed deviation
sentence 偏离仓库 AGENTS is carried by every analysis markdown.
Limits: analysis is static only (no dynamic execution); decompiled text is
machine-generated and unedited; non-PE items have no disassembly by design.
