#include <vector>

struct Beat {
    float amplitude { 0.0f };
};

class Sequencer {
public:
    Sequencer();
    ~Sequencer() = default;

    void toggleKickAt(size_t);
    void toggleSnareAt(size_t);
    void toggleClapAt(size_t);
    void toggleCHatsAt(size_t);

    void updateKickAmplitude(float a, size_t i);
    void updateSnareAmplitude(float a, size_t i);
    void updateClapAmplitude(float a, size_t i);
    void updateCHatsAmplitude(float a, size_t i);

    std::vector<Beat> m_kickTrack;
    std::vector<Beat> m_snareTrack;
    std::vector<Beat> m_clapTrack;
    std::vector<Beat> m_cHatsTrack;

private:
    // Instrument Tracks
};
