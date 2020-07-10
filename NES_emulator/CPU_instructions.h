#pragma once

enum CPUinstructions_official {
	ADC_IM = 0x69, //add with carry
	ADC_ZP = 0x65,
	ADC_ZPX = 0x75,
	ADC_ABS = 0x6D,
	ADC_ABSX = 0x7D,
	ADC_ABSY = 0x79,
	ADC_INDX = 0x61,
	ADC_INDY = 0x71,
	AND_IM = 0x29, //AND operation
	AND_ZP = 0x25,
	AND_ZPX = 0x35,
	AND_ABS = 0x2D,
	AND_ABSX = 0x3D,
	AND_ABSY = 0x39,
	AND_INDX = 0x21,
	AND_INDY = 0x31,
	ASL_ACC = 0x0A, //shift bits left
	ASL_ZP = 0x06,
	ASL_ZPX = 0x16,
	ALS_ABS = 0x0E,
	ALS_ABSX = 0x1E
};