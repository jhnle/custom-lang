#ifndef IPA_H
#define IPA_H

enum Type {
    CONSONANT,
    VOWEL
};

/* Where obstruction occurs during consonant production */
enum Place {
    BILABIAL,
    LABIODENTAL,
    DENTAL,
    ALVEOLAR,
    POST_ALVEOLAR,
    RETROFLEX,
    LABIALIZED_PALATAL,
    POSTALVEOLAR_VELAR,
    ALVEOLO_PALATAL,
    PALATAL,
    LABIAL_VELAR,
    VELAR,
    UVULAR,
    PHARYNGEAL,
    EPIGLOTTAL,
    GLOTTAL
};

/* How articulators are used during consonant production */
enum Manner {
    PLOSIVE,
    IMPLOSIVE,
    EJECTIVE,
    NASAL,
    TRILL,
    FLAP,
    LAT_FLAP,
    FRICATIVE,
    LAT_FRICATIVE,
    EJEC_FRICATIVE,
    EJEC_LAT_FRICATIVE,
    AFFRICATE,
    APPROXIMANT,
    LAT_APPROXIMANT,
    CLICK,
    LAT_CLICK
};

/* Tongue height during vowel production */
enum Height {
    CLOSE,
    NEAR_CLOSE,
    CLOSE_MID,
    MID,
    OPEN_MID,
    NEAR_OPEN,
    OPEN
};

/* Tongue position during vowel production */
enum Part {
    FRONT,
    CENTRAL,
    BACK
};

enum Diacritic {
    VOICELESS = 1,
    VOICED,
    ASPIRATED,
    MORE_ROUNDED,
    LESS_ROUNDED,
    ADVANCED,
    RETRACTED,
    CENTRALIZED,
    MID_CENTRALIZED,
    SYLLABIC,
    NON_SYLLABIC,
    RHOTICITY,
    BREATHY_VOICED,
    CREAKY_VOICED,
    LINGUOLABIAL,
    LABIALIZED,
    PALATALIZED,
    VELARIZED,
    PHARYNGEALIZED,
    VEL_PHA, //Velarized or Pharyngealized
    RAISED,
    LOWERED,
    ADV_TONGUE_ROOT,
    RET_TONGUE_ROOT,
    D_DENTAL,
    APICAL,
    LAMINAL,
    NASALIZED,
    D_EJECTIVE,
    NASAL_REL,
    LAT_REL,
    NO_AUD_REL
};

enum Suprasegmental {
    LONG = 1,
    HALF_LONG,
    EXTRA_SHORT,
    PRIMARY_STRESS,
    SECONDARY_STRESS,
    MINOR_GROUP,
    MAJOR_GROUP,
    SYLLABLE_BREAK,
};

enum Tone_Accent {
    EXTRA_HIGH = 1,
    HIGH,
    T_MID,
    LOW,
    EXTRA_LOW,
    DOWNSTEP,
    UPSTEP,
    RISING,
    FALLING,
    HIGH_RISING,
    LOW_RISING,
    RISING_FALLING,
    GLOBAL_RISE,
    GLOBAL_FALL
};

#endif
