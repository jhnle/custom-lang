#ifndef IPA_H
#define IPA_H

/* Start at 1 to prevent id = 0 */
enum Type {
    CONSONANT = 1,
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

enum Voicing {
    VOICELESS = 1,
    BREATHY_VOICED,
    CREAKY_VOICED,
    VOICED
};

enum Articulation {
    LINGUOLABIAL = 1,
    APICAL,
    LAMINAL,
    ADVANCED,
    RETRACTED,
    CENTRALIZED,
    MID_CENTRALIZED,
    RAISED,
    LOWERED
};

// Secondary Articulation
enum Coarticulation {
    LABIALIZED = 1,
    PALATALIZED,
    VELARIZED,
    PHARYNGEALIZED,
    VEL_PHA, //Velarized or Pharyngealized
    RHOTICIZED,
    NASALIZED
};

// Consonant release
enum Release {
    ASPIRATED = 1,
    NASAL_REL,
    LAT_REL,
    NO_AUD_REL
};

// Vowel lip rounding
enum Rounding {
    UNROUNDED,
    LESS_ROUNDED,
    ROUNDED,
    MORE_ROUNDED
};

enum Length {
    EXTRA_SHORT = 1,
    HALF_LONG,
    LONG,
    EXTRA_LONG
};

enum Tone {
    EXTRA_LOW = 1,
    LOW,
    T_MID,
    HIGH,
    EXTRA_HIGH,
    DOWNSTEP,
    UPSTEP
};

#endif
