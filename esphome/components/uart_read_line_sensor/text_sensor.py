import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import text_sensor, uart
from esphome.const import CONF_ID

DEPENDENCIES = ['uart']

uart_read_line_sensor_ns = cg.esphome_ns.namespace('uart_read_line_sensor')
UartReadLineSensor = uart_read_line_sensor_ns.class_('UartReadLineSensor', cg.Component, uart.UARTDevice, text_sensor.TextSensor)

CONFIG_SCHEMA = text_sensor.TEXT_SENSOR_SCHEMA.extend({
    cv.GenerateID(): cv.declare_id(UartReadLineSensor)
}).extend(cv.COMPONENT_SCHEMA).extend(uart.UART_DEVICE_SCHEMA)

def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    yield text_sensor.register_text_sensor(var, config)
    yield cg.register_component(var, config)
    yield uart.register_uart_device(var, config)
