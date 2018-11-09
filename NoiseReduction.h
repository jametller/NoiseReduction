/**********************************************************************

  Audacity: A Digital Audio Editor

  NoiseReduction.h

  Dominic Mazzoni
  Vaughan Johnson (Preview)
  Paul Licameli

**********************************************************************/

#ifndef __AUDACITY_EFFECT_NOISE_REDUCTION__
#define __AUDACITY_EFFECT_NOISE_REDUCTION__

#include "./MemoryX.h"
#include "Types.h"

#define NOISEREDUCTION_PLUGIN_SYMBOL ComponentInterfaceSymbol{ XO("Noise Reduction") }

class EffectNoiseReduction {
public:

   EffectNoiseReduction();
   virtual ~EffectNoiseReduction();


   bool Init();
   bool CheckWhetherSkipEffect();
   bool Process();

   class Settings;
   class Statistics;

private:
   class Worker;

   std::unique_ptr<Settings> mSettings;
   std::unique_ptr<Statistics> mStatistics;
};

#endif
