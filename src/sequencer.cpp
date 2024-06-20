#include "sequencer.h"

constexpr size_t TRACK_SIZE { 16 };
constexpr float DEFAULT_AMPLITUDE { 0.9f };
constexpr float MAX_AMPLITUDE { 1.0f };

Sequencer::Sequencer()
{
    m_kickTrack.resize(TRACK_SIZE);
    m_snareTrack.resize(TRACK_SIZE);
    m_clapTrack.resize(TRACK_SIZE);
    m_cHatsTrack.resize(TRACK_SIZE);
}

void Sequencer::toggleKickAt(size_t i)
{
    if (i >= TRACK_SIZE) {
        return;
    } else if (m_kickTrack.at(i).amplitude > 0.0f) {
        m_kickTrack.at(i).amplitude = 0.0f;
    } else {
        m_kickTrack.at(i).amplitude = DEFAULT_AMPLITUDE;
    }
}

void Sequencer::toggleSnareAt(size_t i)
{
    if (i >= TRACK_SIZE) {
        return;
    } else if (m_snareTrack.at(i).amplitude > 0.0f) {
        m_snareTrack.at(i).amplitude = 0.0f;
    } else {
        m_snareTrack.at(i).amplitude = DEFAULT_AMPLITUDE;
    }
}

void Sequencer::toggleClapAt(size_t i)
{
    if (i >= TRACK_SIZE) {
        return;
    } else if (m_clapTrack.at(i).amplitude > 0.0f) {
        m_clapTrack.at(i).amplitude = 0.0f;
    } else {
        m_clapTrack.at(i).amplitude = DEFAULT_AMPLITUDE;
    }
}

void Sequencer::toggleCHatsAt(size_t i)
{
    if (i >= TRACK_SIZE) {
        return;
    } else if (m_cHatsTrack.at(i).amplitude > 0.0f) {
        m_cHatsTrack.at(i).amplitude = 0.0f;
    } else {
        m_cHatsTrack.at(i).amplitude = DEFAULT_AMPLITUDE;
    }
}

void Sequencer::updateKickAmplitude(float a, size_t i)
{
    if (i >= TRACK_SIZE) {
        return;
    }
    if (a > MAX_AMPLITUDE) {
        m_kickTrack.at(i).amplitude = MAX_AMPLITUDE;
    } else {
        m_kickTrack.at(i).amplitude = a;
    }
}

void Sequencer::updateSnareAmplitude(float a, size_t i)
{
    if (i >= TRACK_SIZE) {
        return;
    }
    if (a > MAX_AMPLITUDE) {
        m_snareTrack.at(i).amplitude = MAX_AMPLITUDE;
    } else {
        m_snareTrack.at(i).amplitude = a;
    }
}
void Sequencer::updateClapAmplitude(float a, size_t i)
{
    if (i >= TRACK_SIZE) {
        return;
    }
    if (a > MAX_AMPLITUDE) {
        m_clapTrack.at(i).amplitude = MAX_AMPLITUDE;
    } else {
        m_clapTrack.at(i).amplitude = a;
    }
}
void Sequencer::updateCHatsAmplitude(float a, size_t i)
{
    if (i >= TRACK_SIZE) {
        return;
    }
    if (a > MAX_AMPLITUDE) {
        m_cHatsTrack.at(i).amplitude = MAX_AMPLITUDE;
    } else {
        m_cHatsTrack.at(i).amplitude = a;
    }
}
