/* Initial writable cutoffs at RVA 0x22230 and debug key at 0x1a970. */
const char debug_variable_name[] = "__INTEL_LIBIRC_DEBUG";
unsigned long long initial_cache_cutoffs[8] = {
    0x20000, 0x10000, 0x4000, 0x2000, 0x1000, 0x2000, 0x10000, 0x4000
};
