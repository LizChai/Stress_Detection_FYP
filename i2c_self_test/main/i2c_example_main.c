/* i2c - Example

   For other examples please check:
   https://github.com/espressif/esp-idf/tree/master/examples

   See README.md file to get detailed usage of this example.

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "esp_log.h"
#include "driver/i2c.h"
#include "sdkconfig.h"

static const char *TAG = "i2c-example";

#define _I2C_NUMBER(num) I2C_NUM_##num
#define I2C_NUMBER(num) _I2C_NUMBER(num)

// #define DATA_LENGTH 512                  /*!< Data buffer length of test buffer */
// #define RW_TEST_LENGTH 128               /*!< Data length for r/w test, [0,DATA_LENGTH] */
// #define DELAY_TIME_BETWEEN_ITEMS_MS 1000 /*!< delay time between different test items */

// #define I2C_SLAVE_SCL_IO CONFIG_I2C_SLAVE_SCL               /*!< gpio number for i2c slave clock */
// #define I2C_SLAVE_SDA_IO CONFIG_I2C_SLAVE_SDA               /*!< gpio number for i2c slave data */
// #define I2C_SLAVE_SCL_IO CONFIG_I2C_MASTER_SCL              /*!< gpio number for i2c slave clock */
// #define I2C_SLAVE_SDA_IO CONFIG_I2C_MASTER_SDA              /*!< gpio number for i2c slave data */
// #define I2C_SLAVE_NUM I2C_NUMBER(CONFIG_I2C_SLAVE_PORT_NUM) /*!< I2C port number for slave dev */
// #define I2C_SLAVE_TX_BUF_LEN (2 * DATA_LENGTH)              /*!< I2C slave tx buffer size */
// #define I2C_SLAVE_RX_BUF_LEN (2 * DATA_LENGTH)              /*!< I2C slave rx buffer size */

#define I2C_MASTER_SCL_IO CONFIG_I2C_MASTER_SCL               /*!< gpio number for I2C master clock */
#define I2C_MASTER_SDA_IO CONFIG_I2C_MASTER_SDA               /*!< gpio number for I2C master data  */
#define I2C_MASTER_NUM I2C_NUMBER(CONFIG_I2C_MASTER_PORT_NUM) /*!< I2C port number for master dev */
#define I2C_MASTER_FREQ_HZ CONFIG_I2C_MASTER_FREQUENCY        /*!< I2C master clock frequency */
#define I2C_MASTER_TX_BUF_DISABLE 0                           /*!< I2C master doesn't need buffer */
#define I2C_MASTER_RX_BUF_DISABLE 0                           /*!< I2C master doesn't need buffer */

#define HR_SENSOR_ADDR 0x50 /*!< Grove HR Sensor address, 8-bit: 0xA0, 7-bit: 0x50 */
//define BH1750_SENSOR_ADDR CONFIG_BH1750_ADDR   /*!< slave address for BH1750 sensor, NOT USED */
//define BH1750_CMD_START CONFIG_BH1750_OPMODE   /*!< Operation mode, NOT USED */
//define ESP_SLAVE_ADDR CONFIG_I2C_SLAVE_ADDRESS /*!< ESP32 slave address, you can set any 7bit value */
#define ESP_SLAVE_ADDR HR_SENSOR_ADDR /*!< ESP32 slave address, you can set any 7bit value */

#define WRITE_BIT I2C_MASTER_WRITE /*!< I2C master write */
#define READ_BIT I2C_MASTER_READ   /*!< I2C master read */
#define ACK_CHECK_EN 0x1           /*!< I2C master will check ack from slave*/
#define ACK_CHECK_DIS 0x0          /*!< I2C master will not check ack from slave */
#define ACK_VAL 0x0                /*!< I2C ack value */
#define NACK_VAL 0x1               /*!< I2C nack value */

/**
 * @brief i2c master initialization
 */
static esp_err_t i2c_master_init(void)
{
    int i2c_master_port = I2C_MASTER_NUM;
    i2c_config_t conf;
    conf.mode = I2C_MODE_MASTER;
    conf.sda_io_num = I2C_MASTER_SDA_IO;
    conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
    conf.scl_io_num = I2C_MASTER_SCL_IO;
    conf.scl_pullup_en = GPIO_PULLUP_ENABLE;
    conf.master.clk_speed = I2C_MASTER_FREQ_HZ;
    //i2c_filter_enable(i2c_master_port, 2);
    i2c_param_config(i2c_master_port, &conf);
    // i2c_set_timeout(i2c_master_port, 0xFFFFF);
    return i2c_driver_install(i2c_master_port, conf.mode, I2C_MASTER_RX_BUF_DISABLE, I2C_MASTER_TX_BUF_DISABLE, 0);
}

void app_main(void)
{
    ESP_ERROR_CHECK(i2c_master_init());
    uint8_t data_rd;

    while (1)
    {
        data_rd = 0;

        i2c_cmd_handle_t cmd = i2c_cmd_link_create();
        i2c_master_start(cmd);
        i2c_master_write_byte(cmd, (HR_SENSOR_ADDR << 1) | READ_BIT, ACK_CHECK_DIS);
        i2c_master_read_byte(cmd, &data_rd, NACK_VAL);
        i2c_master_stop(cmd);
        esp_err_t ret = i2c_master_cmd_begin(I2C_MASTER_NUM, cmd, 1000 / portTICK_RATE_MS);
        i2c_cmd_link_delete(cmd);

        printf("DataI: %x\n", data_rd);
        //printf("Ret: %x\n", ret);

        if (ret == ESP_ERR_TIMEOUT)
        {
            ESP_LOGE(TAG, "I2C Timeout, Bus is busy");
            vTaskDelay(1000 / portTICK_RATE_MS);
        }
        else if (ret == ESP_OK)
        {
            printf("DataO: %x\n", data_rd);
            printf("Ret: %x\n", ret);
        }
        else
        {
            ESP_LOGW(TAG, "%s: Sensor not connected...\n",
                     esp_err_to_name(ret));
        }
        vTaskDelay(1000 / portTICK_RATE_MS);
    }
}
