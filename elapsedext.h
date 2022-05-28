#pragma once
#include <atomic>
#include <string>
#include <time.h>
#include <chrono>
#include "log.h"
class ElapsedExt {
public:
    ElapsedExt(const std::string desc, bool bRunning = true) :
        m_desc(desc),
        m_duration(0),
        m_times(0) {
        if (bRunning) {
            start_running();
        }
    }
    ~ElapsedExt() {
        if (!m_desc.empty()){
          total_running();
          double sec = m_duration *std::chrono::system_clock::period::num / (double)std::chrono::system_clock::period::den;
          LOG_I("[%d]used time<%s>: %.5f(s)", m_times.load(), m_desc.c_str(), sec);
        }
    }
    void PrintCurrent() {
        total_running();
        double sec = m_duration * std::chrono::system_clock::period::num / (double)std::chrono::system_clock::period::den;
        LOG_I("[%d]current used time<%s>: %.5f(s)", m_times.load(), m_desc.c_str(), sec);
    }
    void Start() {
        start_running();
    }
    void Stop() {
        total_running();
        stop_running();
        m_times++;
    }
    void SetDesc(std::string desc) { m_desc = desc; }
    void Add(ElapsedExt& el){
      if (el.m_bRunning){
        el.Stop();
      }
      m_duration += el.m_duration;
      m_times += el.m_times;
    }
private:
    void stop_running() {
        m_bRunning = false;
    }
    void start_running() {
        m_bRunning = true;
        m_start = std::chrono::system_clock::now().time_since_epoch().count();
    }
    void total_running() {
        if (m_bRunning) {
            std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
            m_duration += end.time_since_epoch().count() - m_start;
            m_start = end.time_since_epoch().count();
        }
    }
    std::atomic<uint64_t> m_duration;
    std::atomic<uint32_t> m_times;
    std::atomic<bool> m_bRunning;
    std::atomic<uint64_t> m_start;
    std::string m_desc;
};

