#ifndef _VCHAT_SERVER_API_TYPES_H_
#define _VCHAT_SERVER_API_TYPES_H_

#include "common.h"
#include "Api/apiTypeNameValuePair.h"

#define MAX_ARRAY 100
#define MAX_LENGTH_METHOD_ID 32
#define MAX_LENGTH_RAW_XML_MESSAGE 4096


////////////////////////////////////////////////////////////////////////////
// defines for dealing with 64 bit integers that work between unix and windows
//	EX:
//		printf(" a long variable["FMT_QUAD"]\n", QUAD(1234567890123456));
#ifdef _WIN32
	#define QUAD(X) X##i64
	#define UQUAD(X) X##ui64
	#define SQUAD(X) X##i64
	#define FMT_QUAD "%I64d"
	#define FMT_QUADU "%I64u"
#else
	#define QUAD(X) X##LL
	#define UQUAD(X) X##ULL
	#define SQUAD(X) X##LL
	#define FMT_QUAD "%lld"
	#define FMT_QUADU "%llu"
#endif



namespace VChatSystem
{
	#define RETURN_TEST(X) if (X != RESULT_SUCCESS) return X;


	typedef unsigned TrackingNumber;
	typedef unsigned TransactionResultCode;
	typedef long long TransactionId;
	typedef unsigned ResultCode;


	enum ResultCode_t
	{
		RESULT_SUCCESS						= 0,
		RESULT_TIMEOUT,
		RESULT_FAILURE,
		RESULT_INVALID_PARAM,
		RESULT_DATABASE_FAILURE,
		RESULT_NETWORK_FAILURE,
		RESULT_NOT_IMPLEMENTED,
		RESULT_NOT_SUPPORTED,
		RESULT_SYSTEM_FAILURE,
        RESULT_PROTOCOL_VIOLATION,        
		RESULT_NOT_FOUND,		
		RESULT_TCP_CONNECTION_NOT_AVAILABLE,
		RESULT_RESPONSE_XML_INVALID,
		RESULT_RESPONSE_VIVOX_FAILURE,
		RESULT_USER_ACCOUNT_BANNED,
		RESULT_NAME_EXCEEDS_VIVOX_LIMIT,
		RESULT_NO_CHANNELS_FOUND_FOR_CHARACTER,

		// vivox error codes
		RESULT_VIVOX_WRONG_USER_CREDENTIALS = 200,
		RESULT_VIVOX_EXPIRED_USER_CREDENTIALS = 201,
		RESULT_VIVOX_MISSING_USER_CREDENTIALS = 202,
		RESULT_VIVOX_USER_NOT_LOGGED_IN = 203,
		RESULT_VIVOX_ACCOUNT_CANT_PERFORM_OP = 212,
		RESULT_VIVOX_FAILED_RETRIEVING_DIR = 220,

		RESULT_VIVOX_PARAMS_MISSING = 300,
		RESULT_VIVOX_UNKNOWN_MODE = 301,
		RESULT_VIVOX_UNABLE_TO_PARSE_ARG = 302,

		RESULT_VIVOX_ACCOUNT_CREATION_FAILED = 400,
		RESULT_VIVOX_ACCOUNT_DEACTIVATE_FAILED = 401,
		RESULT_VIVOX_ACCOUNT_ACTIVATE_FAILED = 402,
		RESULT_VIVOX_ACCOUNT_DOESNT_EXIST = 403,
		RESULT_VIVOX_ACCOUNT_RETRIEVAL_FAILED = 404,
		RESULT_VIVOX_ACCOUNT_UPDATE_FAILED = 405,
		RESULT_VIVOX_ACCOUNT_DELETE_FAILED = 406,

		RESULT_VIVOX_RETRIEVING_SRC_USER = 450,
		RESULT_VIVOX_CHANNEL_ADD_FAILED = 451,
		RESULT_VIVOX_CHANNEL_UPDATE_FAILED = 452,
		RESULT_VIVOX_CHANNEL_RETRIEVE_FAILED = 453,

		RESULT_VIVOX_FEATURE_NAME_UNKNOWN = 500,
		RESULT_VIVOX_FEATURE_RETRIEVAL_FAILED = 501,
		RESULT_VIVOX_FEATURE_SET_FAILED = 502,
		RESULT_VIVOX_FEATURE_UPDATE_FAILED = 503,
		RESULT_VIVOX_FEATURE_DELETE_FAILED = 504,
		RESULT_VIVOX_RETRIEVE_USER_FAILED = 505,
		RESULT_VIVOX_RETRIEVE_FEATURE_LIST_FAILED = 506,

		RESULT_VIVOX_CHANNEL_RETRIEVE_USERS_FAILED = 700,
		RESULT_VIVOX_CHANNEL_MUTE_ALL_FAILED = 701,
		RESULT_VIVOX_CHANNEL_UNMUTE_ALL_FAILED = 702,
		RESULT_VIVOX_CHANNEL_INVITE_FAILED = 703,
		RESULT_VIVOX_CHANNEL_RETRIEVING_ACL_FAILED = 704,
		RESULT_VIVOX_CHANNEL_DELETE_ACL_FAILED = 706,
		RESULT_VIVOX_CHANNEL_LOCKING_FAILED = 707,
		RESULT_VIVOX_CHANNEL_UNLOCKING_FAILED = 708,
		RESULT_VIVOX_CHANNEL_CREATING_FAILED = 709,
		RESULT_VIVOX_CHANNEL_RETRIEVE_FAILED_EX = 710,
		RESULT_VIVOX_USER_NOT_ON_CHANNEL = 711,
		RESULT_VIVOX_UNABLE_TO_COMPLETE_CHANNEL_LOOKUP = 712,

		RESULT_END
	};

	enum CommandType_t
	{
		COMMAND_MUTE = 0,
		COMMAND_UNMUTE,
		COMMAND_KICK,
		COMMAND_HANGUP,
		COMMAND_INVITE,
		COMMAND_BAN,
		COMMAND_UNBAN,
		COMMAND_CHAN_LOCK,
		COMMAND_CHAN_UNLOCK,
		COMMAND_MUTE_ALL,
		COMMAND_UNMUTE_ALL,
		COMMAND_ADD_MODERATOR,
		COMMAND_DELETE_MODERATOR,
		COMMAND_ADD_ACL,
		COMMAND_DELETE_ACL,
		COMMAND_DROP_ALL,
		COMMAND_END
	};
		
	enum ConnectionType
	{
		CONNECTION_TYPE_UNKNOWN = 0,
		CONNECTION_TYPE_VHCAT_SYSTEM		
	};

	enum ChannelType
	{
		CHAN_TYPE_UNKNOWN = 0,
		CHAN_TYPE_DIR,
		CHAN_TYPE_CHANNEL,
		CHAN_TYPE_PROXIMITY
	};

	enum BanStatus
	{
		BAN = 0,
		UNBAN
	};

	//Following from Account Server

	const unsigned MAX_MSG_SIZE=64*1024;
    const unsigned REQ_ID_FIELD_SIZE = 30;
	const unsigned MIN_ACCOUNT_NAME_SIZE = 4;		const unsigned MAX_ACCOUNT_NAME_SIZE = 15;
	const unsigned MIN_ACCOUNT_PASSWORD_SIZE = 5;	const unsigned MAX_ACCOUNT_PASSWORD_SIZE = 255;
	const unsigned MIN_REASON_SIZE = 0;				const unsigned MAX_REASON_SIZE = 2000;
	const unsigned MIN_PASSWORD_SIZE = 8;			const unsigned MAX_PASSWORD_SIZE = 255;
	const unsigned MIN_SECURITY_ANSWER_SIZE = 0;	const unsigned MAX_SECURITY_ANSWER_SIZE = 255;
	const unsigned MIN_EMAIL_SIZE = 0;				const unsigned MAX_EMAIL_SIZE = 255;
	const unsigned MIN_STATION_HANDLE_SIZE = 0;		const unsigned MAX_STATION_HANDLE_SIZE = 31;
	const unsigned MIN_STATION_NAME_SIZE = 0;		const unsigned MAX_STATION_NAME_SIZE = 50;
	const unsigned MIN_MEMBER_TYPE_SIZE = 0;		const unsigned MAX_MEMBER_TYPE_SIZE = 31;
	const unsigned MIN_MEMBER_ID_SIZE = 0;			const unsigned MAX_MEMBER_ID_SIZE = 31;
	const unsigned MIN_RESET_TYPE_SIZE = 0;			const unsigned MAX_RESET_TYPE_SIZE = 31;
	const unsigned MIN_PASSWORD_EMAIL_SIZE = 0;		const unsigned MAX_PASSWORD_EMAIL_SIZE = 255;
	const unsigned MIN_COUNTRY_CODE_SIZE = 2;		const unsigned MAX_COUNTRY_CODE_SIZE = 2;
	const unsigned MIN_COUNTRY_NAME_SIZE = 0;		const unsigned MAX_COUNTRY_NAME_SIZE = 255;
	const unsigned MIN_CURRENCY_SIZE = 0;			const unsigned MAX_CURRENCY_SIZE = 31;
	const unsigned MIN_RESET_ID_SIZE = 0;			const unsigned MAX_RESET_ID_SIZE = 20;
	const unsigned MIN_LANG_SIZE = 2;				const unsigned MAX_LANG_SIZE = 2 + 1 + 2;
	const unsigned MIN_OPTIN_TYPE_SIZE = 0;			const unsigned MAX_OPTIN_TYPE_SIZE = 255;
	const unsigned MIN_OPTIN_ID_SIZE = 0;			const unsigned MAX_OPTIN_ID_SIZE = 255;

	typedef unsigned SessionType_t;    

	/*enum RequestType
    {
        REQUEST_TRANS_INIT_LOOKUP							= 0x0,
        REQUEST_TRANS_AUTH,
        REQUEST_TRANS_AUTH_BRIDGE_LOOKUP,        

		//  Add new request type codes here
        REQUEST_END
    };
*/
   

	enum ApiResultCode
	{
		API_RESULT_UNKNOWN = 0
		,API_RESULT_SUCCESS= 1
		,API_RESULT_FAIL = 2
		,API_RESULT_FAIL_DISCONNECTED
		,API_RESULT_FAIL_RATE_LIMIT_EXCEEDED

        // uncertain result error codes
		,API_RESULT_FAIL_API_TIMEOUT = 100
		,API_RESULT_FAIL_SERVER_TIMEOUT
        ,API_RESULT_FAIL_BAD_MESSAGE_FORMAT
        ,API_RESULT_FAIL_TRANSPORT
        ,API_RESULT_FAIL_READ_MESSAGE
		,API_RESULT_FAIL_SERVER_READ_MESSAGE
		,API_RESULT_FAIL_SERVER_WRITE_MESSAGE

        // API parameter error codeS(do not use for server side)
		,API_RESULT_FAIL_BAD_PARAMS	= 200
		
	};
 
} // end namespace CardinalServerAPI

#endif //_VCHAT_SERVER_API_TYPES_H_
