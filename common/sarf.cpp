#include "sarf.h"

#include <QFile>
#include <cstdio>

#include <emptyprogress.h>

Sarf::Sarf(QObject *parent)
    : QObject(parent), m_errors_stream(), m_input_stream(), m_output_stream(),
      m_sql_manager(nullptr) {
#warning Still unimplemented!
}

Sarf::~Sarf() {
#warning Still unimplemented!
}

bool Sarf::start(QFile *output_file, QFile *errors_file,
                 ATMProgress *progres_reporter) {
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
    if (progres_reporter == nullptr) {
        progres_reporter = new EmptyProgress();
    }
    if (retVal) {
        m_output_stream.setDevice(output_file);
        m_output_stream.setCodec("UTF-8");
        m_errors_stream.setDevice(errors_file);
        m_errors_stream.setCodec("UTF-8");
        //    initialize_variables();
        //    start_connection(progress_reporter);
        //    generate_bit_order("source", source_ids);
        //    generate_bit_order("category", abstract_category_ids, "abstract");
        //    database_info.fill(progress_reporter);
    }

    return false;
}

bool Sarf::start(QString *output_string, QString *errors_string,
                 ATMProgress *progress_reporter) {
#warning Still unimplemented!
    m_output_stream.setString(output_string);
    m_output_stream.setCodec("UTF-8");
    m_errors_stream.setString(errors_string);
    m_errors_stream.setCodec("UTF-8");
    if (progress_reporter == nullptr) {
        progress_reporter = new EmptyProgress();
    }
    //    initialize_variables();
    //    start_connection(progress_reporter);
    //    generate_bit_order("source", source_ids);
    //    generate_bit_order("category", abstract_category_ids, "abstract");
    //    database_info.fill(progress_reporter);
    return false;
}

bool Sarf::stop() {
#warning Still unimplemented!
    return false;
}
