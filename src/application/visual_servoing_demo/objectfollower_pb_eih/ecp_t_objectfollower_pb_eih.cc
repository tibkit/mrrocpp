/*
 * ecp_t_objectfollower_pb_eih.cc
 *
 *  Created on: Apr 21, 2010
 *      Author: mboryn
 */

#include <stdexcept>

#include "ecp_t_objectfollower_pb_eih.h"

#include "../defines.h"

#ifdef ROBOT_P
#include "robot/irp6p_m/ecp_r_irp6p_m.h"
#endif

#ifdef ROBOT_OT
#include "robot/irp6ot_m/ecp_r_irp6ot_m.h"
#endif

#include "../ecp_mp_g_visual_servo_tester.h"

using namespace std;
using namespace mrrocpp::ecp::common::generator;
using namespace logger;
using mrrocpp::ecp_mp::sensor::discode::discode_sensor;

namespace mrrocpp {

namespace ecp {

namespace common {

namespace task {

ecp_t_objectfollower_pb_eih::ecp_t_objectfollower_pb_eih(mrrocpp::lib::configurator& config) :
	common::task::task(config)
{
	try{
#ifdef ROBOT_P
		ecp_m_robot = (boost::shared_ptr<robot_t>) new ecp::irp6p_m::robot(*this);
#endif
#ifdef ROBOT_OT
		ecp_m_robot = (boost::shared_ptr<robot_t>) new ecp::irp6ot_m::robot(*this);
#endif

		char config_section_name[] = { "[object_follower_pb]" };

		log_enabled = true;
		log_dbg_enabled = true;

		shared_ptr <position_constraint> cube(new cubic_constraint(config, config_section_name));

		if(config.exists_and_true("use_pid_regulator", config_section_name)){
			log_dbg("ecp_t_objectfollower_ib: using PID regulator\n");
			reg = shared_ptr <visual_servo_regulator> (new regulator_pid(config, config_section_name));
		} else {
			log_dbg("ecp_t_objectfollower_ib: using P regulator\n");
			reg = shared_ptr <visual_servo_regulator> (new regulator_p(config, config_section_name));
		}


		log_dbg("ecp_t_objectfollower_pb: creating DisCODe sensor\n");
		boost::shared_ptr <discode_sensor> ds = boost::shared_ptr <discode_sensor>(new discode_sensor(config, config_section_name));
		vs = shared_ptr <visual_servo> (new pb_eih_visual_servo(reg, ds, config_section_name, config));

		term_cond = shared_ptr <termination_condition> (new object_reached_termination_condition(config, config_section_name));
		log_dbg("ecp_t_objectfollower_pb::ecp_t_objectfollower_pb(): 3\n");
		sm = shared_ptr <single_visual_servo_manager> (new single_visual_servo_manager(*this, config_section_name, vs));
		log_dbg("ecp_t_objectfollower_pb::ecp_t_objectfollower_pb(): 4\n");
		sm->add_position_constraint(cube);
		//sm->add_termination_condition(term_cond);
		log_dbg("ecp_t_objectfollower_pb: configuring visual_servo_manager\n");
		sm->configure();
	}catch(exception& ex){
		sr_ecp_msg->message(lib::FATAL_ERROR, string("ERROR in ecp_t_objectfollower_pb_eih: ") + ex.what());
		throw ex;
	}
	log_dbg("ecp_t_objectfollower_pb: initialization completed.\n");
}

void ecp_t_objectfollower_pb_eih::main_task_algorithm(void)
{
	while (1) {
		get_next_state();
		if (mp_2_ecp_next_state_string == mrrocpp::ecp_mp::generator::ECP_GEN_VISUAL_SERVO_TEST) {
			sm->Move();
		} else {
			log("ecp_t_objectfollower_pb::main_task_algorithm(void) mp_2_ecp_next_state_string: \"%s\"\n", mp_2_ecp_next_state_string.c_str());
		}
	}

	termination_notice();
}

task_base* return_created_ecp_task(lib::configurator &config)
{
	return new ecp_t_objectfollower_pb_eih(config);
}

} // namespace task

}//namespace common

}//namespace ecp

}//namespace mrrocpp
