#include <Arduino.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"
#include "ADCSensors/adcTest.hpp"

#if CONFIG_IDF_TARGET_ESP32
#define ADC_EXAMPLE_CALI_SCHEME     ESP_ADC_CAL_VAL_EFUSE_VREF
#elif CONFIG_IDF_TARGET_ESP32S2
#define ADC_EXAMPLE_CALI_SCHEME     ESP_ADC_CAL_VAL_EFUSE_TP
#elif CONFIG_IDF_TARGET_ESP32C3
#define ADC_EXAMPLE_CALI_SCHEME     ESP_ADC_CAL_VAL_EFUSE_TP
#elif CONFIG_IDF_TARGET_ESP32S3
#define ADC_EXAMPLE_CALI_SCHEME     ESP_ADC_CAL_VAL_EFUSE_TP_FIT
#endif
esp_adc_cal_characteristics_t adc_chars1;
esp_adc_cal_characteristics_t adc_chars2;


// static bool adc_calibration_init(void)
// {
//     esp_err_t ret;
//     bool cali_enable = false;
//   Serial.println("Hei");
//     ret = esp_adc_cal_check_efuse(ADC_EXAMPLE_CALI_SCHEME);
//     if (ret == ESP_ERR_NOT_SUPPORTED) {
//         Serial.println("Calibration scheme not supported, skip software calibration");
//     } 
//     else if (ret == ESP_ERR_INVALID_VERSION) {
//         Serial.println("eFuse not burnt, skip software calibration");
//     } 
//     else if (ret == ESP_OK) {
//       Serial.println("Hei");
//         cali_enable = true;
        
//         //esp_adc_cal_characterize(ADC_UNIT_2, ADC_EXAMPLE_ATTEN, ADC_WIDTH_BIT_DEFAULT, 0, &adc2_chars);
//     } 
    
//     // 

//     return cali_enable;
// }
// double ReadVoltage(double reading ){
  
//   if(reading < 1 || reading > 4095) return 0;
//   // return -0.000000000009824 * pow(reading,3) + 0.000000016557283 * pow(reading,2) + 0.000854596860691 * reading + 0.065440348345433;
//   return -0.000000000000016 * pow(reading,4) + 0.000000000118171 * pow(reading,3)- 0.000000301211691 * pow(reading,2)+ 0.001109019271794 * reading + 0.034143524634089;
//}

// void setup() {
//   Serial.begin(9600);
//   vTaskDelay(pdMS_TO_TICKS(1000));

  // esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_12, 0, &adc_chars1);
  // esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_9, 0, &adc_chars2);
  // int voltage = 0;
  // bool cali_enable = true;

  // ESP_ERROR_CHECK(adc1_config_width(ADC_WIDTH_BIT_12));
  // ESP_ERROR_CHECK(adc1_config_channel_atten(ADC1_CHANNEL_4, ADC_ATTEN_DB_11));

  
//   for (;;) {
//       int adc_raw = adc1_get_raw(ADC1_CHANNEL_4);

//       if(cali_enable){
//         voltage=esp_adc_cal_raw_to_voltage(adc_raw, &adc_chars1);
//         Serial.print("cali data: ");
//         Serial.println(voltage);
//       }

//       // double voltage2 = ReadVoltage(adc_raw);
//       // Serial.print("polynomial data: ");
//       // Serial.println(voltage2*100);
      

//       vTaskDelay(pdMS_TO_TICKS(500));
//   }
// }

// void loop() {
//   // Your loop code here
// }


void setup() {
Serial.begin(9600);
  adcTest damper1(ADC1_CHANNEL_4);
  adcTest damper2(ADC1_CHANNEL_3);
  adcTest damper3(ADC1_CHANNEL_7);
  adcTest damper4(ADC1_CHANNEL_6);
  while (1){
  Serial.print("Damper 1: ");
  Serial.println(damper1.readVoltage());
  
  Serial.print("Damper 2: ");
  Serial.println(damper2.readVoltage());
  
  Serial.print("Damper 3: ");
  Serial.println(damper3.readVoltage());
  
  Serial.print("Damper 4: ");
  Serial.println(damper4.readVoltage());

  vTaskDelay(pdMS_TO_TICKS(1000));
  }

}

void loop () {


}
