enum {
	ERR_OK,
	ERR_STATE,
	ERR_IGNORE,
	MAX_ERR_ID
};

STATE_ID_e	NowState;

int32_t StateMachine( EVENT_ID_e event_id, MSG_t *p_msg )
{
	STATE_TABLE_t	*p_tbl = NULL;

	if( NowState >= MAX_STATE_ID ) {
		return ERR_STATE;
	}
	p_tbl = &RootStateTable[NowState];
	while( p_tbl->event_id != MAX_EVENT_ID ){
		if( p_tbl->event_id == event_id ){
			return (*p_tbl->event_proc)(p_msg);
		}
		p_tbl++;
	}
	return ERR_IGNORE;
}
