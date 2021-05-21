#include <stdio.h>
#include <QVariant>
#include "globals.h"

QQmlContext *m_rootContext;

void saveRootContext(QQmlContext *context)
{
    m_rootContext = context;
}

QQmlContext* getRootContext()
{
    return m_rootContext;
}
