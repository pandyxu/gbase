#include <assert.h>
#include "test_shm.h"

int main()
{
    struct process_lock_t* pl;
    struct shm_t* shm = shm_create(shmkey, size, 1);
    assert(shm);
    pl = process_lock_init(shmkey);
    assert(pl);

    printf("shm size:%d addr:%p\n", (int)shm_size(shm), (char*)shm_mem(shm));
    printf("press any key to recv shm buffer: \n");

    getchar();
    printf("recv: %s\n", (char*)shm_mem(shm));

    shm_destroy(shm);
    shm_release(shm);

    process_lock_destroy(pl);
    process_lock_release(pl);
    return 0;
}
