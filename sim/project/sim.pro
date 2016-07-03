CONFIG += c++11
CONFIG += object_parallel_to_source
CONFIG += qt
QT     += core gui widgets serialport network
QMAKE_CFLAGS += -std=c99

LIBS += -lwinmm


INCLUDEPATH += \
    ../src \
    ../src/platform \
    ../../src/main \
    ../3rd_party/WMM/src

QMAKE_LFLAGS += "-T $$PWD/linker.ld"

DEFINES += \
    __TARGET__=\\\"X_PLANE\\\" \
    __REVISION__=\\\"1.0.0\\\" \
    _USE_MATH_DEFINES \
    NAZE \
    STM32F10X

	
FORMS += \
    ../src/cMainWindow.ui

HEADERS += \
    ../src/cLcdDisplay.h \
    ../src/cMainWindow.h \
    ../src/cSerialPortsWidget.h \
    ../src/main.h
    
SOURCES += \
    ../src/cLcdDisplay.cpp \
    ../src/cMainWindow.cpp \
    ../src/cSerialPortsWidget.cpp \
    ../src/emulation.cpp \
    ../src/execution.cpp \
    ../src/geomag.cpp \
    ../src/input.cpp \
    ../src/reset.cpp \
    ../src/xplane.cpp \
    ../src/platform/hardware_revision.c \
    ../3rd_party/WMM/src/GeomagnetismLibrary.c \
    ../../src/main/blackbox/blackbox.c \
    ../../src/main/common/colorconversion.c \
    ../../src/main/common/encoding.c \
    ../../src/main/common/filter.c \
    ../../src/main/common/maths.c \
    ../../src/main/common/printf.c \
    ../../src/main/common/streambuf.c \
    ../../src/main/common/typeconversion.c \
    ../../src/main/config/config.c \
    ../../src/main/config/config_streamer.c \
    ../../src/main/config/feature.c \
    ../../src/main/config/parameter_group.c \
    ../../src/main/config/profile.c \
    ../../src/main/config/runtime_config.c \
    ../../src/main/flight/altitudehold.c \
    ../../src/main/flight/failsafe.c \
    ../../src/main/flight/gps_conversion.c \
    ../../src/main/flight/gtune.c \
    ../../src/main/flight/imu.c \
    ../../src/main/flight/mixer.c \
    ../../src/main/flight/navigation.c \
    ../../src/main/flight/pid.c \
    ../../src/main/flight/pid_luxfloat.c \
    ../../src/main/flight/pid_mw23.c \
    ../../src/main/flight/pid_mwrewrite.c \
    ../../src/main/flight/servos.c \
    ../../src/main/rx/ibus.c \
    ../../src/main/rx/msp.c \
    ../../src/main/rx/pwm.c \
    ../../src/main/rx/rx.c \
    ../../src/main/rx/sbus.c \
    ../../src/main/rx/spektrum.c \
    ../../src/main/rx/sumd.c \
    ../../src/main/rx/sumh.c \
    ../../src/main/rx/xbus.c \
    ../../src/main/sensors/acceleration.c \
    ../../src/main/sensors/barometer.c \
    ../../src/main/sensors/battery.c \
    ../../src/main/sensors/boardalignment.c \
    ../../src/main/sensors/compass.c \
    ../../src/main/sensors/gyro.c \
    ../../src/main/sensors/initialisation.c \
    ../../src/main/sensors/sensors.c \
    ../../src/main/sensors/sonar.c \
    ../../src/main/telemetry/frsky.c \
    ../../src/main/telemetry/hott.c \
    ../../src/main/telemetry/ltm.c \
    ../../src/main/telemetry/mavlink.c \
    ../../src/main/telemetry/smartport.c \
    ../../src/main/telemetry/telemetry.c \
    ../../src/main/build_config.c \
    ../../src/main/debug.c \
    ../../src/main/main.c \
    ../../src/main/mw.c \
    ../../src/main/scheduler.c \
    ../../src/main/scheduler_tasks.c \
    ../../src/main/version.c \
    ../../src/main/blackbox/blackbox_io.c \
    ../../src/main/io/beeper.c \
    ../../src/main/io/display.c \
    ../../src/main/io/flashfs.c \
    ../../src/main/io/gimbal.c \
    ../../src/main/io/gps.c \
    ../../src/main/io/ledstrip.c \
    ../../src/main/io/motor_and_servo.c \
    ../../src/main/io/msp.c \
    ../../src/main/io/rate_profile.c \
    ../../src/main/io/rc_adjustments.c \
    ../../src/main/io/rc_controls.c \
    ../../src/main/io/rc_curves.c \
    ../../src/main/io/serial.c \
    ../../src/main/io/serial_4way.c \
    ../../src/main/io/serial_4way_avrootloader.c \
    ../../src/main/io/serial_4way_stk500v2.c \
    ../../src/main/io/serial_cli.c \
    ../../src/main/io/serial_msp.c \
    ../../src/main/io/statusindicator.c \
    ../../src/main/io/transponder_ir.c \
    ../../src/main/config/config_eeprom.c \
    ../../src/main/drivers/gyro_sync.c \
    ../../src/main/drivers/serial.c \
    ../../src/main/drivers/buf_writer.c \
    ../src/drivers/flash.cpp \
    ../src/drivers/serial.cpp \
    ../src/main.cpp \
    ../src/drivers/light_led.cpp

