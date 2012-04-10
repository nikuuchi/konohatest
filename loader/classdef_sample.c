#include "../src/minivm/konoha2.h"
#include "mod_sample.h"

static int __init__  = 0;
static int __free__  = 0;

static void Sample_init(CTX, kObject *o, void *conf)
{
	assert((uintptr_t)conf == 0xdeadbeaf);
	((kSample*)o)->x = __init__++;
}

static void Sample_free(CTX, kObject *o)
{
	__free__++;
}

KDEFINE_CLASS SampleDef = {
	.structname   = "Sample",
	.cid          = 200,/*TODO*/
	.cflag        = 2,
	.cstruct_size = sizeof(struct Sample),
	.init     = Sample_init,
	.free     = Sample_free
};
