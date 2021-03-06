
typedef enum {
	// 要求待ち
	STATE_REQ,
	// DATA待ち
	STATE_DATA,
	// ACK待ち
	STATE_ACK,
	MAX_STATE_ID
} STATE_ID_e;

typedef enum {
	// WRQイベント
	EVENT_WRQ,
	// RRQイベント
	EVENT_RRQ,
	// DATAイベント
	EVENT_DATA,
	// ACKイベント
	EVENT_ACK,
	// タイムアウトイベント
	EVENT_TMO,
	MAX_EVENT_ID
} EVENT_ID_e;

typedef struct {
	EVENT_ID_e		event_id;
	int32_t			(*event_proc)(MSG_t *msg);
} STATE_TABLE_t;

STATE_TABLE_t	STATE_REQ_Table[] = {
	{ EVENT_WRQ,		receivedWRQ },
	{ EVENT_RRQ,		receivedRRQ },
	{ MAX_EVENT_ID,		NULL }
};

STATE_TABLE_t	STATE_DATA_Table[] = {
	{ EVENT_DATA,		receivedDATA },
	{ EVENT_TMO,		receivedDATA_TMO },
	{ MAX_EVENT_ID,		NULL }
};

STATE_TABLE_t	STATE_ACK_Table[] = {
	{ EVENT_ACK,		receivedACK },
	{ EVENT_TMO,		receivedACK_TMO },
	{ MAX_EVENT_ID,		NULL }
};

STATE_TABLE_t	*RootStateTable[MAX_STATE_ID] = {
	STATE_REQ_Table,
	STATE_DATA_Table,
	STATE_ACK_Table,
};

//TODO: move to Top line
int32_t receivedWRQ( MSG_t *msg );
int32_t receivedRRQ( MSG_t *msg );
int32_t receivedDATA( MSG_t *msg );
int32_t receivedDATA_TMO( MSG_t *msg );
int32_t receivedACK( MSG_t *msg );
int32_t receivedACK_TMO( MSG_t *msg );
//TODO: end

int32_t receivedWRQ( MSG_t *msg )
{
	// →DATA待ち/無遷移
}

int32_t receivedRRQ( MSG_t *msg )
{
	// →ACK待ち/無遷移
}

int32_t receivedDATA( MSG_t *msg )
{
	// →要求待ち/無遷移
}

int32_t receivedDATA_TMO( MSG_t *msg )
{
	// →要求待ち
}

int32_t receivedACK( MSG_t *msg )
{
	// →要求待ち/無遷移
}

int32_t receivedACK_TMO( MSG_t *msg )
{
	// →要求待ち
}

