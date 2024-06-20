#include "cursed_engine.h"
#include "sequencer.h"
#include <format>

int main()
{
    CursedEngine c;
    if (!c.initialize()) {
        return EXIT_FAILURE;
    }

    c.print("Program Title\n", TypeStyle::Title);
    c.print("Program description.\n", TypeStyle::Body);

    c.print("TODO\n", TypeStyle::Title);
    c.print("\t- Create Settings struct\n", TypeStyle::Body);

    c.print("\t- Create Sequencer struct\n", TypeStyle::Body);
    Sequencer seq {};
    c.print("\t\t- Create Kick struct\n", TypeStyle::Body);
    for (auto k : seq.m_kickTrack) {
        c.print(std::format("{} ", k.amplitude).c_str(), TypeStyle::Body);
    }
    c.print("\n", TypeStyle::Body);
    for (auto i = 0; i != 16; ++i) {
        if (i % 2 == 0) {
            seq.toggleCHatsAt(i);
            seq.updateCHatsAmplitude(0.5, i);
        }
        if (i == 0 || i == 4) {
            seq.toggleKickAt(i);
        } else if (i == 4 || i == 12) {
            seq.toggleSnareAt(i);
        }
    }
    c.print("With beat:\nKick: ", TypeStyle::Body);
    for (auto k : seq.m_kickTrack) {
        c.print(std::format("{} ", k.amplitude).c_str(), TypeStyle::Body);
    }
    c.print("\nSnare: ", TypeStyle::Body);
    for (auto s : seq.m_snareTrack) {
        c.print(std::format("{} ", s.amplitude).c_str(), TypeStyle::Body);
    }
    c.print("\nHats: ", TypeStyle::Body);
    for (auto h : seq.m_cHatsTrack) {
        c.print(std::format("{} ", h.amplitude).c_str(), TypeStyle::Body);
    }
    c.print("\n", TypeStyle::Body);
    c.print("\t\t- Create Snare struct\n", TypeStyle::Body);
    c.print("\t\t- Create Clap struct\n", TypeStyle::Body);
    c.print("\t\t- Create ClosedHats struct\n", TypeStyle::Body);

    c.print("\t- Create Transport struct\n", TypeStyle::Body);
    c.print("\t- Define Tempo\n", TypeStyle::Body);
    c.print("\t- Define isPlaying getter\n", TypeStyle::Body);

    c.print("\t- Create Audio components\n", TypeStyle::Body);
    c.print("\t\t- Create Sine wavetable\n", TypeStyle::Body);
    c.print("\t\t- Create Triangle wavetable\n", TypeStyle::Body);
    c.print("\t\t- Create Noise wavetable\n", TypeStyle::Body);
    c.print("\t\t- Create ASDR envelope\n", TypeStyle::Body);
    c.print("\t\t- Create Pitch envelope\n", TypeStyle::Body);
    c.print("\t\t- Create LP filter\n", TypeStyle::Body);
    c.print("\t\t- Create HP filter\n", TypeStyle::Body);

    c.print("\t- Create AudioEngine\n", TypeStyle::Body);
    c.print("\t\t- Validate Settings reference\n", TypeStyle::Body);
    c.print("\t\t- Define audio callback\n", TypeStyle::Body);
    c.print("\t\t- Define Play method\n", TypeStyle::Body);
    c.print("\t\t- Define Stop method\n", TypeStyle::Body);

    c.wait();

    return EXIT_SUCCESS;
}
