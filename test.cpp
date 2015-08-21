#include <android/log.h>
#include <time.h>

#define  LOG_TAG   "bench"

#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

clock_t begin, end;
double time_spent;

const int LOOP_BOUND = 200000000;

__attribute__((noinline))
static int add(const int& x, const int& y) {
    return x + y;
}

__attribute__((noinline))
static int work(int xval, int yval) {
    int sum(0);
    for (int i=0; i<LOOP_BOUND; ++i) {
        int x(xval+sum);
        int y(yval+sum);
        int z = add(x, y);
        sum += z;
    }
    return sum;
}

int main(int , char* argv[]) {
    int result;
    begin = clock();
    result = work(*argv[1], *argv[2]);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    LOGD("time: %f\n", time_spent);
    return result;
}
