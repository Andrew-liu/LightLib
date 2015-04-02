#include "Thread.h"
#include <assert.h>

Thread::Thread()
    :tid_(0),
     isStarted_(false)
{
}

Thread::Thread(const ThreadFunc &callback)
    :tid_(0),
     isStarted_(false),
     callback_(callback)
{
}

Thread::~Thread()
{
    if(isStarted_)
        pthread_detach(tid_);
}

void Thread::setCallback(const ThreadFunc &cb)
{
    callback_ = cb;
}


void *Thread::threadFunc(void *arg)
{
    Thread *pt = static_cast<Thread *>(arg);
    assert(pt->callback_);
    pt->callback_();  //调用线程逻辑

    return NULL;
}


void Thread::start()
{
    pthread_create(&tid_, NULL, threadFunc, this);
}

void Thread::join()
{
     pthread_join(tid_, NULL);
}

