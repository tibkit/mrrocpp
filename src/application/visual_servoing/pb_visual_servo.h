/*
 * pb_visual_servo.h
 *
 *  Created on: May 26, 2010
 *      Author: mboryn
 */

#ifndef PB_VISUAL_SERVO_H_
#define PB_VISUAL_SERVO_H_

#include "visual_servo.h"
#include "PBReading.h"

namespace mrrocpp {

namespace ecp {

namespace servovision {

/** @addtogroup servovision
 *  @{
 */

/**
 *
 */
class pb_visual_servo : public visual_servo
{
public:
			pb_visual_servo(boost::shared_ptr <visual_servo_regulator> regulator, boost::shared_ptr <
					mrrocpp::ecp_mp::sensor::discode::discode_sensor> sensor, const std::string& section_name, mrrocpp::lib::configurator& configurator);
	virtual ~pb_visual_servo();
protected:
	virtual void retrieve_reading();
	virtual bool is_object_visible_in_latest_reading();

	Types::Mrrocpp_Proxy::PBReading reading;

	lib::Homog_matrix G_T_E_desired;
};

/** @} */

}//namespace generator {

}

}

#endif /* PB_VISUAL_SERVO_H_ */
