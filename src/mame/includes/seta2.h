class seta2_state : public driver_data_t
{
public:
	static driver_data_t *alloc(running_machine &machine) { return auto_alloc_clear(&machine, seta2_state(machine)); }

	seta2_state(running_machine &machine)
		: driver_data_t(machine) { }

	UINT16 *vregs;
	int yoffset;
	int keyboard_row;

	UINT16 *spriteram;
	size_t spriteram_size;
	UINT16 *buffered_spriteram;
	UINT32 *coldfire_regs;

	UINT8 *funcube_outputs;
	UINT8 *funcube_leds;

	UINT64 funcube_coin_start_cycles;
	UINT8 funcube_hopper_motor;
	UINT8 funcube_press;

	UINT8 funcube_serial_fifo[4];
	UINT8 funcube_serial_count;
};

/*----------- defined in video/seta2.c -----------*/

WRITE16_HANDLER( seta2_vregs_w );

VIDEO_START( seta2 );
VIDEO_START( seta2_offset );
VIDEO_UPDATE( seta2 );
VIDEO_EOF( seta2 );


