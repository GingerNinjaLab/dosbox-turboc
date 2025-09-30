#define TOTAL_LEVELS 101
#define ERROR_DISCERROR=1
#define MAP_WIDTH 38
#define MAP_HEIGHT 20
#define MAP_LEVEL_SIZE 775
#define FILE_BUFFER_SIZE 2100
#define MAP_MARKER 255
#define MAP_LEVEL_NAME_LENGTH 15
#define MAP_LEVELS_PER_FILE 4
#define MAP_FILE_COUNT 34
#define MAP_VDU_RADIUS 3
#define NPC_MAX 20
#define NPC_TYPES 8
#define DIFFICULTY_MAX_HP 100
/*Gods chance is the level out of 10 it has to go */
#define GODS_CHANGE_MAX 10
#define GODS_CHANCE_DEFAULT 2
#define GODS_EXP_MAX 250
#define NPC_RANGE 6
#define DOORSLAM_MAX_DAMAGE 3
#define CHEST_DAMAGE_CHANCE 3
#define CHEST_DAMAGE_MAX 3

#if defined(__MSDOS__)
#define VDU_OFFSET +1
#else
#define VDU_OFFSET 
#endif

#define VDU_DIVIDER_X 0
#define VDU_DIVIDER_Y 21
#define VDU_HP_X 0
#define VDU_HP_Y 23
#define VDU_GOLD_X 8
#define VDU_GOLD_Y 23
#define VDU_EXP_X 17
#define VDU_EXP_Y 23
#define VDU_KEYS_X 25
#define VDU_KEYS_Y 23
#define VDU_MSG_X 1
#define VDU_MSG_Y 22
#define VDU_MSG_WIDTH 38


#define MAX_KEYS 5

#define NPC_ORC 111
#define NPC_DEMON 100
#define NPC_ELEMENTAL 101
#define NPC_GHOST 103
#define NPC_KOBALD 107
#define NPC_MINOTOUR 109
#define NPC_SKELETON 115
#define NPC_RAT 114

#define GAMEMODE_MENU 1
#define GAMEMODE_HELP 2
#define GAMEMODE_LOADING 3 
#define GAMEMODE_MAIN 4
#define GAMEMODE_DEAD 5
#define GAMEMODE_END 6
#define GAMEMODE_QUIT 7
#define GAMEMODE_GODS 8
#define GAMEMODE_TEST 9

/*Keyboard mapping */
#define KEY_UPPER_HELP 'H'
#define KEY_LOWER_HELP 'h'
#define KEY_UPPER_UP 'W'
#define KEY_LOWER_UP 'w'
#define KEY_UPPER_LEFT 'A'
#define KEY_LOWER_LEFT 'a'
#define KEY_UPPER_DOWN 'S'
#define KEY_LOWER_DOWN 's'
#define KEY_UPPER_RIGHT 'D'
#define KEY_LOWER_RIGHT 'd'
#define KEY_UPPER_N 'N'
#define KEY_LOWER_N 'n'
#define KEY_UPPER_Y 'Y'
#define KEY_LOWER_Y 'y'
#define KEY_UPPER_Q 'Q'
#define KEY_LOWER_Q 'q'
#define KEY_UPPER_START 'S'
#define KEY_LOWER_START 's'

#define KEY_ESC 27

#if defined(__CBM__) || defined(__APPLE__) || defined(__ATMOS__)

#else

#endif

#if defined(__MSDOS__)
#define INKEY(); k = getch();
#else
#define INKEY(); k = cgetc();
#endif

#if defined(__MSDOS__)
#define PUTCHAR putch
#else
#define PUTCHAR cputc
#endif

#define KEY_ESCAPE 27
#define KEY_UPPER_TEST 'T'
#define KEY_LOWER_TEST 't'
#define KEY_UPPER_QUIT 'Q'
#define KEY_LOWER_QUIT 'q'

/*VDU Text values */
/*Message items */
#if defined(__CBM__)             
#define VDU_STATUS "hp:%i keys:%i gold:%i xp:%i lvl:%i  "
#define VDU_MSG_FOUNDFOOD "found food!"
#define VDU_MSG_TOOMUCHFOOD "found food, urgh!"
#define VDU_MSG_FOUNDKEY "found a key!"
#define VDU_MSG_FOUNDGOLD "found gold!"
#define VDU_MSG_DOORLOCKED "door locked!"
#define VDU_MSG_UNLOCKED_DOOR "unlocked door"
#define VDU_MSG_WATER "freezing water drains hp!"
#define VDU_MSG_ATTACKS_YOU " attacks you"
#define VDU_MSG_FEELING_WEAK "feeling weak!"
#define VDU_MSG_YOU_KILLED "you killed the "
#define VDU_MSG_YOU_ATTACK "you attack the "
#define VDU_MSG_SWITCH "you hear a click"
#define VDU_MSG_TRANSPORTER "hidden passage!"
#define VDU_MSG_TRAP "a trap!"
#define VDU_MSG_VOID "you fell into the void!"
#define VDU_MSG_CHEST_NOKEY "you need a key to open the chest"
#define VDU_MSG_CHEST_OPEN "you open the chest"
#define VDU_MSG_CHEST_TRAP "the chest is booby trapped!"
#define VDU_MSG_DOOR_SMASH "you hammer on the door"
#define VDU_MSG_DOOR_SMASHED "you smashed open the door"
#define VDU_MSG_TOO_MANY_KEYS "too many keys"
#define VDU_GODS_GRANT "the gods accept!"
#define VDU_GODS_DENY "the gods deny!"

/*CHEAT MESSAGES */
#define VDU_MSG_CHEAT_MSG "1:hp 2:k 3:g 4:e 5:l- 6:l+ 7:r 8:v 9:s"
#define VDU_MSG_CHEAT_HP "+10 hp (100 max)"
#define VDU_MSG_CHEAT_NEXT_LEVEL "next level"
#define VDU_MSG_CHEAT_PREV_LEVEL "prec level"
#define VDU_MSG_CHEAT_KEY "+1 key"
#define VDU_MSG_CHEAT_EXP "+1 exp"
#define VDU_MSG_CHEAT_GOLD "+10 gold"
#define VDU_MSG_RESTORE "restore all"
#define VDU_MSG_CANNOTFALL "cannot fall into void"
#define VDU_MSG_CANFALL "void can kill"
#define VDU_MSG_CHEAT_SET "setting state"

/*OTHER TEXT */
#define VDU_MSG_QUIT "are you sure you want to quit? y/n"
#define VDU_MSG_QUITING "      quitting the dungeon...     "
#define VDU_MSG_ENTER_LEVEL "()==[===entering level===>"
#define VDU_MSG_ERROR1 "dark forces have"
#define VDU_MSG_ERROR2 "cast an error spell"
#define VDU_MSG_FILE_ERROR "unable to load map (%s)"
#define VDU_MSG_ANY_KEY "    -= press any key to restart =-"

#define NPC_NAME_ORC "orc"
#define NPC_NAME_DEMON "demon"
#define NPC_NAME_ELEMENTAL "elemental"
#define NPC_NAME_GHOST "ghost"
#define NPC_NAME_KOBALD "kobald"
#define NPC_NAME_MINOTOUR "minotour"
#define NPC_NAME_SKELETON "skeleton"
#define NPC_NAME_RAT "gianr rat"


#define NPC_DISPLAY_ORC 79
#define NPC_DISPLAY_DEMON 68
#define NPC_DISPLAY_ELEMENTAL 69
#define NPC_DISPLAY_GHOST 71
#define NPC_DISPLAY_KOBALD 75
#define NPC_DISPLAY_MINOTOUR 77
#define NPC_DISPLAY_SKELETON 83
#define NPC_DISPLAY_RAT 82

#else
#define VDU_STATUS "HP:%i KEYS:%i GOLD:%i XP:%i LVL:%i  "
#define VDU_MSG_FOUNDFOOD "Found food!"
#define VDU_MSG_TOOMUCHFOOD "Found food, urgh!"
#define VDU_MSG_FOUNDKEY "Found a key!"
#define VDU_MSG_FOUNDGOLD "Found gold!"
#define VDU_MSG_DOORLOCKED "Door locked!"
#define VDU_MSG_UNLOCKED_DOOR "Unlocked door"
#define VDU_MSG_WATER "Freezing water drains HP!"
#define VDU_MSG_ATTACKS_YOU " Attacks you"
#define VDU_MSG_FEELING_WEAK "Feeling weak!"
#define VDU_MSG_YOU_KILLED "You killed the "
#define VDU_MSG_YOU_ATTACK "You attack the "
#define VDU_MSG_SWITCH "You hear a click"
#define VDU_MSG_TRANSPORTER "Hidden passage!"
#define VDU_MSG_TRAP "A trap!"
#define VDU_MSG_VOID "You fell into the void!"
#define VDU_MSG_CHEST_NOKEY "You need a key to open the chest"
#define VDU_MSG_CHEST_OPEN "You open the chest"
#define VDU_MSG_CHEST_TRAP "The chest is booby trapped!"
#define VDU_MSG_DOOR_SMASH "You hammer on the door"
#define VDU_MSG_DOOR_SMASHED "You smashed open the door"
#define VDU_MSG_TOO_MANY_KEYS "Too many keys"
#define VDU_GODS_GRANT "The gods accept!"
#define VDU_GODS_DENY "The gods deny!"

/*Cheat messages */
#define VDU_MSG_CHEAT_MSG "1:HP 2:K 3:G 4:E 5:L- 6:L+ 7:R 8:V 9:S"
#define VDU_MSG_CHEAT_HP "+10 hp (100 max)"
#define VDU_MSG_CHEAT_NEXT_LEVEL "Next level"
#define VDU_MSG_CHEAT_PREV_LEVEL "Prev level"
#define VDU_MSG_CHEAT_KEY "+1 key"
#define VDU_MSG_CHEAT_EXP "+1 EXP"
#define VDU_MSG_CHEAT_GOLD "+10 Gold"
#define VDU_MSG_RESTORE "Restore all"
#define VDU_MSG_CANNOTFALL "Cannot fall into void"
#define VDU_MSG_CANFALL "Void can kill"
#define VDU_MSG_CHEAT_SET "Setting state"

/*Other text */
#define VDU_MSG_QUIT "Are you sure you want to quit? Y/N"
#define VDU_MSG_QUITING "     Quitting the dungeon...      "
#define VDU_MSG_ENTER_LEVEL "()==[===entering level===>"
#define VDU_MSG_ERROR1 "Dark forces have"
#define VDU_MSG_ERROR2 "cast an error spell"
#define VDU_MSG_FILE_ERROR "Unable to load map (%s)"
#define VDU_MSG_ANY_KEY "    -= Press and key to restart =-"

#define NPC_NAME_ORC "Orc"
#define NPC_NAME_DEMON "Demon"
#define NPC_NAME_ELEMENTAL "Elemental"
#define NPC_NAME_GHOST "Ghost"
#define NPC_NAME_KOBALD "Kobald"
#define NPC_NAME_MINOTOUR "Minotour"
#define NPC_NAME_SKELETON "Skeleton"
#define NPC_NAME_RAT "Gianr Rat"

#define NPC_DISPLAY_ORC 111
#define NPC_DISPLAY_DEMON 100
#define NPC_DISPLAY_ELEMENTAL 101
#define NPC_DISPLAY_GHOST 103
#define NPC_DISPLAY_KOBALD 107
#define NPC_DISPLAY_MINOTOUR 109
#define NPC_DISPLAY_SKELETON 115
#define NPC_DISPLAY_RAT 114

#endif

/*Machine specific character changes and file names */
#if defined(__APPLE2__)             
#define FILE_INTRO "i.txt"
#define FILE_MENU "m.txt"
#define FILE_HELP "aph.txt"
#define FILE_DEAD "d.txt"
#define FILE_END "e.txt"
#define FILE_GODS "g.txt"
#define TILE_BASE_WATER '~'
#define TILE_MACHINE_WATER 34
#define TILE_BASE_VERTICAL '|'
#define TILE_MACHINE_VERTICAL 'I'
#elif defined(__CBM__)
#define FILE_INTRO "ci.txt"
#define FILE_MENU "cm.txt"
#define FILE_HELP "ch.txt"
#define FILE_DEAD "cd.txt"
#define FILE_END "ce.txt"
#define FILE_GODS "cg.txt"
#define TILE_BASE_WATER '~'
#define TILE_MACHINE_WATER 168
#define TILE_BASE_VERTICAL '|'
#define TILE_MACHINE_VERTICAL 98
#define TILE_BASE_RIGHT '/'
#define TILE_MACHINE_RIGHT 110
#define TILE_BASE_SLASH 92
#define TILE_MACHINE_SLASH 109
#define TILE_BASE_TREE '^'
#define TILE_MACHINE_TREE 97
#elif defined(__MSDOS__)
#define FILE_INTRO "di.txt"
#define FILE_MENU "dm.txt"
#define FILE_HELP "dh.txt"
#define FILE_DEAD "dd.txt"
#define FILE_END "de.txt"
#define FILE_GODS "dg.txt"
#define TILE_BASE_WATER '~'
#define TILE_MACHINE_WATER '~'
#define TILE_BASE_VERTICAL '|'
#define TILE_MACHINE_VERTICAL 98
#define TILE_BASE_RIGHT '/'
#define TILE_MACHINE_RIGHT 110
#define TILE_BASE_SLASH 92
#define TILE_MACHINE_SLASH 109
#define TILE_BASE_TREE '^'
#define TILE_MACHINE_TREE 97
#else
#define FILE_INTRO "i.txt"
#define FILE_MENU "m.txt"
#define FILE_HELP "h.txt"
#define FILE_DEAD "d.txt"
#define FILE_END "e.txt"
#define FILE_GODS "g.txt"

#define TILE_BASE_WATER '~'
#define TILE_MACHINE_WATER '~'
#define TILE_BASE_VERTICAL '|'
#define TILE_MACHINE_VERTICAL '|'
#endif

#define CHAR_INVERSE_OFFSET 128
#define SWITCH_FLASH_COUNT 3
#define BLIP_COUNT 5000

/*Play testing and cheat settings */
#define CHEAT_SET_HP 25
#define CHEAT_SET_KEYS 2
#define CHEAT_SET_GOLD 1586
#define CHEAT_SET_EXP 421
#define CHEAT_SET_LEVEL 100

#define MAX_GOLD 10
#define MAX_FOOD 6

#define xSize 40
#define ySize 25

typedef struct {
	unsigned char x,y;
	unsigned char ox,oy;
	unsigned char type;
	signed char hp;
	unsigned char attack;
	unsigned char icon;
} Npc;

typedef struct {
	unsigned char type[NPC_TYPES];
	unsigned char hp[NPC_TYPES];
	unsigned char attack[NPC_TYPES];
} NpcType;

/*
Orc
Ogre
Skeleton
Kobold
Ghost
Giant rat
*/

/*Setup the system, screen mode and dimensions */
void Setup();

/*Show the Intro screen */
void Intro();

/*Reset all varaibles such as level and HP when starting a new game */
void NewGame();

/*Goto the next level, or end */
void NextLevel();

/*Goto previous level */
void PrevLevel();

/*Game has ended, show the results */
void EndGame();

/*Load the current map */
void LoadMap();

/*Show Map */
void ShowMap();

/*Show NPC */
void ShowNPCs();

/*Add NPCs to map */
void AddNPCs();

/*Load information screen */
void LoadScreen(const char* filename);

/*Main game loop */
void GameLoop();

/*Error */
void ErrorHandler(const char* text);

/*Show debug top left */
/*void Debug(const char* text); */

void ClearFileName();

void ProcessMove();

void ShowMessage(char *msg);

void ClearMessage();

void UpdateStats();

unsigned char RandomNumber();

void ShowDialog(char *title);

void ClearDialog();

void ConfirmQuit();

void PrintNpcName(unsigned char npcType);

void MoveNPCs();

#ifdef __DEBUG__
void ShowNpcData();
#endif

void WriteScores(unsigned char showLevel);

void ShowMessageNoPad(char *msg);

void ShowVersion();

void SetStatus();

void WaitBlip();

void ClearKeyboardBuffer();

void FindDisplayPos();

void PrayToGods();

void Test();

int TestFile(const char* filename);
