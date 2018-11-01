#ifndef HT_FEATURE_CALLSTACK_H
#define HT_FEATURE_CALLSTACK_H

#include <hawktracer/core_events.h>
#include <hawktracer/timeline.h>

HT_DECLS_BEGIN

#define HT_FEATURE_CALLSTACK 0

HT_API HT_ErrorCode ht_feature_callstack_enable(HT_Timeline* timeline);

HT_API void ht_feature_callstack_disable(HT_Timeline* timeline);

HT_API void ht_feature_callstack_start(HT_Timeline* timeline, HT_CallstackBaseEvent* event);

HT_API void ht_feature_callstack_stop(HT_Timeline* timeline);

HT_API void ht_feature_callstack_start_int(HT_Timeline* timeline, HT_CallstackEventLabel label);

HT_API void ht_feature_callstack_start_string(HT_Timeline* timeline, const char* label);

HT_API size_t ht_feature_callstack_get_snapshot(HT_Timeline* timeline, int* out_data, size_t max_size);

HT_DECLS_END

#endif /* HT_FEATURE_CALLSTACK_H */
