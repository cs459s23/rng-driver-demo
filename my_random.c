#include "qemu/osdep.h"
#include "qapi/error.h" /* provides error_fatal() handler */
#include "qemu/log.h"
#include "qemu/module.h"
#include "hw/sysbus.h"
#include "qom/object.h"
#include "my_rng.h"
#include "stdio.h"

#define TYPE_MY_RNG "my-rng"
OBJECT_DECLARE_SIMPLE_TYPE(MyRNGState, MY_RNG)

struct MyRNGState {
    SysBusDevice parent_obj;
    MemoryRegion iomem;
};

static uint64_t my_rng_read(void *opaque, hwaddr addr, unsigned size)
{
    //printf("Read rng");
    return (uint64_t)rand();
}

static void my_rng_write(void *opaque, hwaddr addr, uint64_t value, unsigned size)
{
    // no-op, the device is read-only
}

static const MemoryRegionOps my_rng_ops = {
    .read = my_rng_read,
    .write = my_rng_write,
    .endianness = DEVICE_NATIVE_ENDIAN,
};

static void my_rng_init(Object *obj)
{
    MyRNGState *s = MY_RNG(obj);
    SysBusDevice *sbd = SYS_BUS_DEVICE(obj);

    memory_region_init_io(&s->iomem, obj, &my_rng_ops, s, "my-rng", 4);
    sysbus_init_mmio(sbd, &s->iomem);
}

static const TypeInfo my_rng_info = {
    .name = TYPE_MY_RNG,
    .parent = TYPE_SYS_BUS_DEVICE,
    .instance_size = sizeof(MyRNGState),
    .instance_init = my_rng_init,
};
static void my_rng_register_types(void)
{
    type_register_static(&my_rng_info);
}

DeviceState *my_rng_create(hwaddr addr)
{
    DeviceState *dev = qdev_new(TYPE_MY_RNG);
    sysbus_realize_and_unref(SYS_BUS_DEVICE(dev), &error_fatal);
    sysbus_mmio_map(SYS_BUS_DEVICE(dev), 0, addr);
    return dev;
}

type_init(my_rng_register_types)


