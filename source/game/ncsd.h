#pragma once

#include "common.h"

#define NCSD_MEDIA_UNIT 0x200

// see: https://www.3dbrew.org/wiki/NCSD
typedef struct {
	u32 offset;
	u32 size;
} __attribute__((packed)) NcchPartition;

// see: https://www.3dbrew.org/wiki/NCSD
typedef struct {
	u8  signature[0x100];
	u8  magic[4];
	u32 size;
	u64 mediaId;
	u8  partitions_fs_type[8];
	u8  partitions_crypto_type[8];
	NcchPartition partitions[8];
	u8  hash_exthdr[0x20];
	u8  size_addhdr[0x4];
	u8  sector_zero_offset[0x4];
	u8  partition_flags[8];
	u8  partitionId_table[8][8];
	u8  reserved[0x40];
} __attribute__((packed, aligned(16))) NcsdHeader;

u32 ValidateNcsdHeader(NcsdHeader* header);
