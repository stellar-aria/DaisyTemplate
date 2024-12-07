#include <daisy_seed.h>

#include <algorithm>
#include <ranges>
#include <span>

using namespace daisy;

DaisySeed hw;

/// @brief Simple representation of stereo samples
struct StereoSample {
  float l;
  float r;
};

/** Function that gets called at a regular interval by the hardware to
 *  process, and/or generate audio signals
 */
void InterleavingAudioCallback(AudioHandle::InterleavingInputBuffer in,    //< input
                               AudioHandle::InterleavingOutputBuffer out,  //< output
                               size_t size) {                              //< buffer size (in samples)

  // Turn those messy C arrays into proper views of the stereo samples
  std::span input_span{reinterpret_cast<const StereoSample*>(in), size / 2};
  std::span output_span{reinterpret_cast<StereoSample*>(out), size / 2};

  // bypass
  std::copy(input_span.cbegin(), input_span.cend(), output_span.begin());

  /*
  // to really operate on the samples one-by-one, access them like so:
  for (auto&& [input_sample, output_sample] : std::views::zip(input_span, output_span)) {
    output_sample.l = input_sample.l;
    output_sample.r = input_sample.r;
  }
  */
}

int main(void) {
  /** Basic initialization of Daisy hardware */
  hw.Configure();
  hw.Init();

  /** And start the audio callback */
  hw.StartAudio(InterleavingAudioCallback);
  while (1) {
  }
}
