#ifndef _ALL_KILL_MACROS_H_
#define _ALL_KILL_MACROS_H_ 


enum E_AllKillGameStatus
{
	AK_Ready=0,
	AK_Start=1,
	AK_EndGame=2
};



enum E_AllKillGameCmd 
{
	AK_LOGIN_C=1001,
	AK_LOGIN_SUCC_SU=4000,
	AK_LOGIN_ERR_SU=4002,

	AK_LOGOUT_C=1002,

	AK_LOGOUT_SUCC_SU=4004,
	AK_LOGOUT_ERR_SU=4005,

	AK_GAME_INFO_SU=6001,
	AK_GAME_READY_SB=6002,
	AK_GAME_START_SB=6003,
	AK_GAME_END_SB=6004,
	AK_GAME_UPDATE_SB=6005,
	AK_PLAYER_BET_C=6006,
	AK_PLAYER_BET_RESULT_SU=6007,
	AK_ASK_ROLE_C=6008,
	AK_ASK_ROLE_RESULT_SU=6009,
	AK_ASK_UN_ROLE_C=6010,
	AK_ASK_UN_ROLE_RESULT_SU=6012,
	AK_ASK_ROLE_LIST_CHANGE_SB=6013,

	AK_PLAYER_BET_REWARD_SU=6014,

	AK_CHAT_C=6021,
	AK_CHAT_SB=6031,

	AK_ASK_SERVER_SHUT_DOWN=-1,
};


enum E_AllKillGameErr 
{
	AK_BET_NU_ERR=-1,
	AK_STATUS_ERR=-2,
	AK_SEAT_ID_ERR=-3,
	AK_MONEY_NOT_ENOUGH=-4,
	AK_NOT_IN_ROLE_LIST=-5,
    AK_BET_LIMIT = -6,          //下注额度限制
};


/* ak seat info */
#define AK_SEAT_ID_START 1
#define AK_SEAT_ID_END	4
#define AK_SEAT_ID_NU 4

/* ak game timer */
//#define AK_START_TIME 30
#define AK_START_TIME 20
//#define AK_END_GAME_TIME 15 
#define AK_END_GAME_TIME 10 
//#define AK_READY_TIME 4
#define AK_READY_TIME 2
#define AK_UPDATE_TIME 1
#define AK_ROTTLE_OPEN_TIME 5
#define AK_SET_NEXT_ROLE_BEFORE_TIME 3


#define VALID_CLIENT_UID_MIN 10000


/* default role info */
#define AK_DEFAULT_ROLE_NAME "系统女王"
#define AK_DEFAULT_ROLE_MONEY 99999999
#define AK_DEFAULT_ROLE_AVATAR "image_0.png"
#define AK_DEFAULT_ROLE_UID 0




#define AK_BET_FLOW_ID 301 
#define AK_ROTTLE_FLOW_ID 302

//上桌玩家数量
#define AK_DECKPLAYER_NU 6

#endif /*_ALL_KILL_MACROS_H_*/

