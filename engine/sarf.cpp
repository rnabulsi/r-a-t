#include "sarf.h"

#include <QFile>
#include <QTextCodec>
#include <common.h>
#include <sqlmanager.h>

#include <cstdio>

#include "emptyprogress.h"

Sarf::Sarf(QObject *parent)
    : QObject(parent), m_errors_stream(), m_input_stream(), m_output_stream(), m_invalid_bitset(MAX_SOURCES) {
#warning Still unimplemented!
    m_invalid_bitset.setBit(MAX_SOURCES - 1);
}

Sarf::~Sarf() {
#warning Still unimplemented!
}

bool Sarf::start(QFile *output_file, QFile *errors_file, ATMProgress *progress_reporter) {
#warning Still unimplemented!
    bool retVal = true;
    if (output_file == nullptr) {
        output_file = new QFile();
        if (!output_file->open(stdout, QIODevice::WriteOnly)) {
            delete output_file;
            output_file = nullptr;
            retVal = false;
        }
    }
    if (errors_file == nullptr) {
        errors_file = new QFile();
        if (!errors_file->open(stderr, QIODevice::ReadOnly)) {
            delete errors_file;
            errors_file = nullptr;
            retVal = false;
        }
    }
    if (progress_reporter == nullptr) {
        progress_reporter = new EmptyProgress();
    }
    if (retVal) {
        m_output_stream.setDevice(output_file);
        m_output_stream.setCodec("UTF-8");
        m_errors_stream.setDevice(errors_file);
        m_errors_stream.setCodec("UTF-8");
        initializeVariables();
        retVal = SqlManager::instance().start(progress_reporter);
    }
    if (retVal) {
        //    generate_bit_order("source", source_ids);
        //    generate_bit_order("category", abstract_category_ids, "abstract");
        //    database_info.fill(progress_reporter);
    } else {
        m_errors_stream << "SQL Engine failed to initialize.";
    }
    return retVal;
}

bool Sarf::start(QString *output_string, QString *errors_string, ATMProgress *progress_reporter) {
#warning Still unimplemented!
    bool retVal = true;

    m_output_stream.setString(output_string);
    m_output_stream.setCodec("UTF-8");
    m_errors_stream.setString(errors_string);
    m_errors_stream.setCodec("UTF-8");
    if (progress_reporter == nullptr) {
        progress_reporter = new EmptyProgress();
    }
    initializeVariables();
    retVal = SqlManager::instance().start(progress_reporter);
    if (retVal) {
        //    generate_bit_order("source", source_ids);
        //    generate_bit_order("category", abstract_category_ids, "abstract");
        //    database_info.fill(progress_reporter);
        m_output_stream << "Engine started.";
    } else {
        m_errors_stream << "SQL Engine failed to initialize.";
    }
    return retVal;
}

bool Sarf::stop() {
#warning Still unimplemented!
    return false;
}

void Sarf::initializeVariables() { QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8")); }
#include "moc_sarf.cpp"
