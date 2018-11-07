# Introduction
The aim of this project is isolating the audacity Noise Reduction plugin so that it can be executed as a command line application.
# Reverse Engineering
## Structure

### Effect class

Audacity effects are implemented by extending the class Effect which provides several methods to be extended. Audacity uses the common interface to polimorphycally invoke and configure plugins through their base clase.

### Effect class

Normally plugins also implement a Dialog class which is used to implement the effect pop up window through which the user introduces parameters and executes actions for these specific effect.

### Statistics class

### Worker class

## Behaviour

Main Entry point methods to the effect are:

- PromptUser: Pops up the dialog to the user requesting parameters and actions and fills the class Settings with the values introduced.
- Init: Method devoted to initialize internal values. In the case of Noise Reduction it does nothing.
- Process: This is the main method. Basically it will do the follwing actions:
  - Get a reference to the track
  - It will identify if we are profiling the noise or actually reducing it.
  - It creates a worker class and calls process method of the worker
  - Then it seems to iteratively process fixed size windows (2048 samples each)
  - The method processOne processes one window and for each one, statistics are calculated (GatherStatistics) and Noise Reduction is applied (ReduceNoise).

## Dependencies

The effect has several dependencies. Some of them are an independent file which can be used as is and it does not link to 3rd files. Several other dependencies are hardly linking the effect to audacity and these ones have to be broken or some fake dependency needs to be created to avoid depending on audacity code.

- Wx widgets graphic library
- MemoryX header
- Effect class
- WaveTrack class
- ...

# Tasks

- Make NoiseReduction not derive from Effect DONE
- Adapt calls to base class methods PENDING
- Break dependency between MemoryX and wxMin wxMax function DONE (it can be improved)
- Delete Dialog class DONE
- Fill Settings class with hardcoded default values DONE
- Make a fake WaveTrack class (PENDING)
- Make a main method creating noise reduction PENDING
- Discover format of wav files and how they are translated to float arrays PENDING