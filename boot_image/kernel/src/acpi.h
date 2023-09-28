#ifndef __ACPI_H__
#define __ACPI_H__

#include <stdint.h>
#include <stddef.h>

typedef struct {
    char signature[8];
    uint8_t checksum;
    char oem_id[6];
    uint8_t rev;
    uint32_t rsdt_addr;
    /* ver 2.0 only */
    uint32_t length;
    uint64_t xsdt_addr;
    uint8_t ext_checksum;
    uint8_t reserved[3];
} __attribute__((packed)) rsdp_t;

typedef struct {
    char signature[4];
    uint32_t length;
    uint8_t rev;
    uint8_t checksum;
    char oem_id[6];
    char oem_table_id[8];
    uint32_t oem_rev;
    uint32_t creator_id;
    uint32_t creator_rev;
} __attribute__((packed)) acpi_sdt_t;

typedef struct {
    acpi_sdt_t sdt;
    uint32_t sdt_ptr[];
} __attribute__((packed)) rsdt_t;

typedef struct {
    acpi_sdt_t sdt;
    uint64_t sdt_ptr[];
} __attribute__((packed)) xsdt_t;

typedef struct {
    acpi_sdt_t sdt;
    uint32_t lapic_addr;
    uint32_t flags;
} __attribute__((packed)) madt_t;


extern rsdp_t *rsdp;
extern rsdt_t *rsdt;
extern xsdt_t *xsdt;

void init_acpi();
void *acpi_find_sdt(const char *, int);
int acpi_get_sci_irq(void);
void acpi_init_ec(void);

#endif
