#ifndef ECP_WII_RELATIVE_GENERATOR_H
#define ECP_WII_RELATIVE_GENERATOR_H

#include <string.h>
#include <math.h>

#include "ecp/common/generator/ecp_generator.h"
#include "application/wii_teach/sensor/ecp_mp_s_wiimote.h"
#include "application/wii_teach/generator/ecp_g_wii.h"

namespace mrrocpp {
namespace ecp {
namespace irp6ot {
namespace generator {

class wii_relative : public irp6ot::generator::wii
{
    public:
	/**
	 * Tworzy generator odtwarzajacy orientacje kontrolera
	 * @param zadanie
	 * @param major_axis wartosc wiekszej polosi
	 * @param minor_axis wartosc mniejszej polosi
	 * @author jedrzej
	 */
        wii_relative (common::task::task& _ecp_task,ecp_mp::sensor::wiimote* _wiimote);

        /**
         * Generuje pierwszy krok
         * @author jedrzej
         */
        virtual bool first_step();

        void preset_position(void);
};

}
} // namespace irp6ot
} // namespace ecp
} // namespace mrrocpp

#endif //ECP_WII_RELATIVE_GENERATOR_H