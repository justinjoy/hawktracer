#ifndef HAWKTRACER_PARSER_PROTOCOL_READER_HPP
#define HAWKTRACER_PARSER_PROTOCOL_READER_HPP

#include "parser/event_klass.hpp"
#include "parser/stream.hpp"

#include <atomic>
#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>

namespace HawkTracer
{
namespace parser
{

class ProtocolReader
{
public:
    using OnNewEventCallback = std::function<void(const Event&)>;

    ProtocolReader(std::unique_ptr<Stream> stream);
    ~ProtocolReader();

    void register_events_listener(OnNewEventCallback callback);

    bool start();
    void stop();

    void wait_for_complete();

private:
    void _read_events();
    void _read_event(bool& is_error, Event& event, Event* base_event);
    bool _read_string(FieldType& value);
    bool _read_numeric(FieldType& value, const EventKlassField& field);
    bool _read_struct(FieldType& value, const EventKlassField& field, Event* event, Event* base_event);

    void _call_callbacks(const Event& event);

    std::vector<OnNewEventCallback> _on_new_event_callbacks;
    std::unique_ptr<Stream> _stream;
    std::thread _thread;
    std::atomic_bool _is_running;
    std::condition_variable _cv;
    std::mutex _mtx_cv;
};

} // namespace parser
} // namespace HawkTracer

#endif // HAWKTRACER_PARSER_PROTOCOL_READER_HPP
