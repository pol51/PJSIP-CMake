#include <pj/log.h>
#include <pj/os.h>
#include <android/log.h>


static void term_set_color(int level)
{
  PJ_UNUSED_ARG(level);
}

static void term_restore_color(void)
{
}

PJ_DEF(void) pj_log_write(int level, const char *buffer, int len)
{
  PJ_CHECK_STACK();
  PJ_UNUSED_ARG(len);

  __android_log_print(6 - level + ANDROID_LOG_DEFAULT, "PJSIP", "%s", buffer);
}

