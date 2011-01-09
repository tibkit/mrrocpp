#ifndef __UI_SR_H
#define __UI_SR_H

#include <QMainWindow>

#include <boost/function.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/circular_buffer.hpp>
#include <stdexcept>
#include <iostream>
#include <string>
#include <list>

#include "base/lib/com_buf.h"
#include "base/lib/sr/srlib.h"

//#include "ui/src/ui.h"

namespace mrrocpp {
namespace ui {
namespace common {

class sr_buffer : public boost::noncopyable
{
private:
	MainWindow& mw;
	boost::thread thread_id;
	boost::circular_buffer <lib::sr_package_t> cb;
	boost::mutex mtx;

	static const int UI_SR_BUFFER_LENGHT = 50;

public:
	sr_buffer(MainWindow& _mw);

	~sr_buffer();

	//! main thread loop
	void operator()();

	void put_one_msg(const lib::sr_package_t& new_msg); // podniesienie semafora
	void get_one_msg(lib::sr_package_t& new_msg); // podniesienie semafora
	bool buffer_empty(); // czy bufor cykliczny jest pusty
};

}
} //namespace ui
} //namespace mrrocpp
#endif

