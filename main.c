#include <zephyr.h>
#include <device.h>
#include <drivers/usb/usb_device.h>
#include <zephyr/logging/log.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/gatt.h>
#include <bluetooth/services/hog.h>

LOG_MODULE_REGISTER(xb2ps, LOG_LEVEL_INF);

/* PS4 USB HID report length */
#define PS4_REPORT_LEN  91
#define PS4_REPORT_ID   0x01

/* Byte indices */
enum {
    B_LEFT_STICK_X = 1,
    B_LEFT_STICK_Y,
    B_RIGHT_STICK_X,
    B_RIGHT_STICK_Y,
    B_DPAD_FACE,
    B_SHOULDER_BUTTONS,
    B_PACKET_CNT,
    B_L3R3_LO,
    B_L3R3_HI,
    B_TIMESTAMP_LO,
    B_TIMESTAMP_HI,
    B_BATTERY,
    /* bytes 13–26: set to 0x00 */
    B_DATA_START = 27,
};

/* HID report buffer */
static uint8_t hid_report[PS4_REPORT_LEN];

/* Placeholder: fill in with data from Xbox BLE controller */
static void fill_report_from_xbox(const uint8_t *xbox_data)
{
    hid_report[0] = PS4_REPORT_ID;
    /* map sticks/buttons here... */
    /* set unused bytes to 0 */
    for (int i = 13; i < PS4_REPORT_LEN; i++) {
        hid_report[i] = 0x00;
    }
}

void main(void)
{
    int err;

    /* Initialize USB HID */
    err = usb_enable(NULL);
    if (err) {
        LOG_ERR("Failed to enable USB");
        return;
    }
    LOG_INF("USB HID started");

    /* Initialize BLE stack */
    err = bt_enable(NULL);
    if (err) {
        LOG_ERR("Bluetooth init failed (err %d)", err);
        return;
    }
    LOG_INF("Bluetooth initialized");

    /* TODO:
     * - Discover & connect to Xbox BLE controller (HOGP)
     * - Subscribe to its HID reports
     * - In callback, call fill_report_from_xbox()
     * - Send hid_report over USB using hid_int_ep_write()
     */

    /* Main loop — placeholder */
    while (1) {
        k_sleep(K_SECONDS(1));
    }
}
