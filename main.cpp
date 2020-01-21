#include <iostream>
#include <iomanip>

// Note https://www.h-schmidt.net/FloatConverter/IEEE754.html

bool test_and_report(uint32_t uint32_mask)
{
	const float casted_float_mask = (float)uint32_mask;
	const uint32_t uint32_casted_float_mask = (uint32_t)casted_float_mask;
	if (uint32_mask != uint32_casted_float_mask)
	{
		const float reinterpreted_float_mask = *reinterpret_cast<float*>(&uint32_mask);
		const uint32_t uint32_casted_reinterpreted_float_mask = (uint32_t)reinterpreted_float_mask;
		const uint32_t uint32_reinterpreted_reinterpreted_float_mask = *(uint32_t*)&reinterpreted_float_mask;

		std::cout	<< "------\n"
					<< "uint32_mask\t\t\t\t\t0x" << std::hex << std::setw(8) << std::setfill('0') << uint32_mask << "\t" << std::dec << uint32_mask << std::endl << std::endl

					<< "casted_float_mask\t\t\t\t" << casted_float_mask << std::endl
					<< "uint32_casted_float_mask\t\t\t0x" << std::hex << std::setw(8) << std::setfill('0') << uint32_casted_float_mask << "\t" << std::dec << uint32_casted_float_mask << std::endl << std::endl

					<< "reinterpreted_float_mask\t\t\t" << reinterpreted_float_mask << std::endl
					<< "uint32_casted_reinterpreted_float_mask\t\t0x" << std::hex << std::setw(8) << std::setfill('0') << uint32_casted_reinterpreted_float_mask << std::endl
					<< "uint32_reinterpreted_reinterpreted_float_mask\t0x" << std::setw(8) << std::setfill('0') << uint32_reinterpreted_reinterpreted_float_mask << std::endl << std::endl;
		
		return false;
	}

	return true;
}

int main(int /*argc*/, char** /*argv*/)
{
	for (uint32_t uint32_mask = 0x00000000; uint32_mask != 0xFFFFFFFF; ++uint32_mask)
	{
		if (!test_and_report(uint32_mask))
			break;
	}

	uint32_t uint32_mask = 0xFFFFFFFF;
	test_and_report(uint32_mask);

	return 0;
}