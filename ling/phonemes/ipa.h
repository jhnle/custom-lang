#ifndef IPA_H
#define IPA_H

enum class Type {
    suprasegmental,
    consonant,
    vowel
};

enum class Voicing {
    voiceless,
    voiced
};

// CONSONANTS

/* Where obstruction occurs during consonant production */
enum class Place {
    bilabial,
    labiodental,
    dental,
    alveolar,
    postAlveolar,
    retroflex,
    labPalatal,     // Labialized Palatal
    postalvVel,     // Postalveolar Velar
    alvPalatal,     // Alveolo Palatal
    palatal,
    labialVelar,
    velar,
    uvular,
    pharyngeal,
    epiglottal,
    glottal
};

/* How articulators are used during consonant production */
enum class Manner {
    plosive,
    implosive,
    ejective,
    nasal,
    trill,
    flap,
    latFlap,
    fricative,
    latFricative,
    ejecFricative,
    ejecLatFricative,
    affricate,
    approximant,
    latApproximant,
    click,
    latClick
};

enum class Articulation {
    linguolabial = 1,
    apical,
    laminal,
    advanced,
    retracted,
    centralized,
    midCentralized,
    raised,
    lowered
};

// Secondary Articulation
enum class Coarticulation {
    labialized = 1,
    palatalized,
    velarized,
    pharyngealized,
    velPha,            //Velarized or Pharyngealized
    rhoticized,
    nasalized
};

enum class Release {
    aspirated = 1,
    nasalRel,
    latRel,
    noAudRel
};

// VOWELS

/* Tongue height during vowel production */
enum class Height {
    close,
    nearClose,
    closeMid,
    mid,
    openMid,
    nearOpen,
    open
};

/* Tongue position during vowel production */
enum class Backness {
    front,
    central,
    back
};

// Vowel lip rounding
enum class Rounding {
    unrounded,
    lessRounded,
    rounded,
    moreRounded
};

enum class TongueRoot {
    retracted = 1,
    advanced
};

// SUPRASEGMENTALS

enum class Length {
    extra_short,
    half_long,
    llong,
    extra_long
};

enum Tone {
    extraLow,
    low,
    mid,
    high,
    extraHigh,
    Downstep,
    Upstep
};

#endif
