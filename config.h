#define NUMCOLORS       13
#define MODKEY          Mod2Mask
#define MONKEY          Mod4Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      toggleview,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      view,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      toggletag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      tag,      {.ui = 1 << TAG} },

static const unsigned int tagspacing = 3;       /* space between tags */
static const unsigned int tagpadding = 25;      /* inner padding of tags */
static const unsigned int taglinepx = 2;        /* height of tag underline */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const Bool showsystray = True;           /* false means no systray */
static const unsigned int gappx = 8;            /* gaps between windows */
static const unsigned int borderpx = 1;         /* border pixel of windows */
static const unsigned int snap = 32;            /* snap pixel */
static const Bool showbar = True;               /* false means no bar */
static const Bool topbar = True;                /* false means bottom bar */
static const float mfact = 0.50;                /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;                   /* number of clients in master area */
static const Bool resizehints = False;          /* true means respect size hints in tiled resizals */
static const char font[] = "-artwiz-cure-medium-*-*-*-11-*-*-*-*-*-iso8859-*";

static const char colors[NUMCOLORS][ColLast][13] = {
    /* border    fg         bg */
    { "#2D2D2D", "#FFFFFF", "#2D2D2D" },        /* 01 - regular */
    { "#3E6A82", "#FFFFFF", "#2D2D2D" },        /* 02 - selected */
    { "#2D2D2D", "#FF0000", "#2D2D2D" },        /* 03 - urgent */
    { "#2D2D2D", "#666666", "#2D2D2D" },        /* 04 - occupied */
    { "#2D2D2D", "#A82222", "#2D2D2D" },        /* 05 - red */
    { "#2D2D2D", "#1F7B94", "#2D2D2D" },        /* 06 - blue */
    { "#2D2D2D", "#349147", "#2D2D2D" },        /* 07 - green */
    { "#2D2D2D", "#666666", "#2D2D2D" },        /* 08 - dark grey */
    { "#2D2D2D", "#DCDCDC", "#2D2D2D" },        /* 09 - light grey */
    { "#2D2D2D", "#D64937", "#2D2D2D" },        /* 0A - orange */
    { "#2D2D2D", "#B86A6A", "#2D2D2D" },        /* 0B - pink */
    { "#2D2D2D", "#FFFFFF", "#2D2D2D" },        /* 0C - white */
    { "#2D2D2D", "#000000", "#2D2D2D" },        /* 0D - black */
};

static const Layout layouts[] = {
    /* symbol   gaps    arrange */
    { "\x84",      True,   tile },
    { "\x87",      True,   bstack },
    { "\x81",      False,  monocle },
    { "\x85",      False,  NULL },
};

static const Tag tags[] = {
    /* name     layout          mfact   nmaster */
    { "\x9a",    &layouts[0],    -1,     -1 },
    { "\x91",   &layouts[2],    -1,     -1 },
    { "\x89",   &layouts[0],    -1,     -1 },
    { "\x8a",   &layouts[3],    -1,     -1 },
};

static const Rule rules[] = {
    /* class                instance    title       tags mask       isfloating      iscentred       monitor */
    { "Google-chrome",      NULL,       NULL,       1 << 1,         False,          False,          -1 },
    { "URxvt",              NULL,       NULL,       1 << 3,         True,           True,          -1 },
    { "xterm",             NULL,       NULL,       1 << 2,         True,           True,           -1 },
};

static const char *menu[] = { "dmenu_run", "-i", "-fn", font, "-nb", colors[0][ColBG], "-nf", colors[0][ColFG], "-sb", colors[1][ColBG], "-sf", colors[9][ColFG], NULL };
static const char *webb[] = { "google-chrome", NULL, "Google-chrome" };
static const char *term[] = { "uxterm", NULL };
static const char *edit[] = { "xterm vim", NULL, "vim" };
static const char *file[] = { "xterm ranger", NULL, "ranger" };
static const char *prts[] = { "scrot", NULL };
static const char *play[] = { "ncmpcpp", "toggle" };
static const char *stop[] = { "ncmpcpp", "stop" };
static const char *prev[] = { "ncmpcpp", "prev" };
static const char *next[] = { "ncmpcpp", "next" };
static const char *mute[] = { "amixer", "-q", "set", "PCM", "toggle", NULL };
static const char *volu[] = { "amixer", "-q", "set", "PCM", "5%+", "unmute", NULL };
static const char *vold[] = { "amixer", "-q", "set", "PCM", "5%-", "unmute", NULL };

static Key keys[] = {
    { MODKEY,           XK_p,       spawn,          {.v = menu } },
    { MODKEY,           XK_n,  runorraise,     {.v = term } },
    { MONKEY,           XK_v,       runorraise,     {.v = edit } },
    { MONKEY,           XK_e,       runorraise,     {.v = file } },
    { MONKEY,           XK_Print,   spawn,          {.v = prts } },
    { MONKEY,           XK_F5,      spawn,          {.v = play } },
    { MONKEY,           XK_F6,      spawn,          {.v = stop } },
    { MONKEY,           XK_F7,      spawn,          {.v = prev } },
    { MONKEY,           XK_F8,      spawn,          {.v = next } },
    { MONKEY,           XK_F10,     spawn,          {.v = mute } },
    { MONKEY,           XK_F11,     spawn,          {.v = vold } },
    { MONKEY,           XK_F12,     spawn,          {.v = volu } },
    { MODKEY|ShiftMask, XK_w,       quit,           {0} },
    { MODKEY|ShiftMask, XK_b,       togglebar,      {0} },
    { MODKEY,           XK_w,       killclient,     {0} },
    { MODKEY,           XK_Return,  zoom,           {0} },
    { MODKEY,           XK_Tab,     view,           {0} },
    { MODKEY|ShiftMask, XK_f,       togglefloating, {0} },
    { MODKEY,           XK_space,   setlayout,      {0} },
    { MODKEY,           XK_t,       setlayout,      {.v = &layouts[0] } },
    { MODKEY,           XK_b,       setlayout,      {.v = &layouts[1] } },
    { MODKEY,           XK_m,       setlayout,      {.v = &layouts[2] } },
    { MODKEY,           XK_f,       setlayout,      {.v = &layouts[3] } },
    { MODKEY,           XK_k,   focusstack,     {.i = +1 } },
    { MODKEY,           XK_j,    focusstack,     {.i = -1 } },
    { MODKEY,           XK_h,       setmfact,       {.f = -0.05 } },
    { MODKEY,           XK_l,       setmfact,       {.f = +0.05 } },
    { MODKEY,           XK_i,   incnmaster,     {.i = +1 } },
    { MODKEY,           XK_u,   incnmaster,     {.i = -1 } },
    { MODKEY,           XK_0,       view,           {.ui = ~0 } },
    { MODKEY|ShiftMask, XK_0,       tag,            {.ui = ~0 } },
    { MODKEY,           XK_comma,   focusmon,       {.i = -1 } },
    { MODKEY,           XK_period,  focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask, XK_comma,   tagmon,         {.i = -1 } },
    { MODKEY|ShiftMask, XK_period,  tagmon,         {.i = +1 } },
    TAGKEYS(            XK_1,       0)
    TAGKEYS(            XK_2,       1)
    TAGKEYS(            XK_3,       2)
    TAGKEYS(            XK_4,       3)
};


static Button buttons[] = {
    { ClkLtSymbol,      0,          Button1,        setlayout,      {0} },
    { ClkClientWin,     MODKEY,     Button2,        movemouse,      {0} },
    { ClkClientWin,     MODKEY,     Button1,        togglefloating, {0} },
    { ClkClientWin,     MODKEY,     Button3,        resizemouse,    {0} },
    { ClkTagBar,        0,          Button1,        view,           {0} },
    { ClkTagBar,        0,          Button3,        toggleview,     {0} },
    { ClkTagBar,        MODKEY,     Button1,        tag,            {0} },
    { ClkTagBar,        MODKEY,     Button3,        toggletag,      {0} },
};

