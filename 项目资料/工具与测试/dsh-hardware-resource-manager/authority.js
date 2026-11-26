export function authoritySnapshot(policy) {
  return JSON.stringify([policy.mode, policy.workspaceRoot, policy.sessionId, policy.additionalWritableRoots ?? []]);
}
