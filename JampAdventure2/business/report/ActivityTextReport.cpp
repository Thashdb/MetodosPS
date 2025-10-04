#include "ActivityTextReport.h"

#include <sstream>

std::string ActivityTextReport::renderHeader(const UsageStats& stats) const {
    std::ostringstream out;
    out << "===============================\n";
    out << "RELATORIO DE ATIVIDADES\n";
    out << "===============================\n";
    out << "Usuarios: " << stats.totalUsers << " (" << stats.totalInstructors
        << " instrutores, " << stats.totalStudents << " alunos)\n";
    out << "Atividades: " << stats.totalActivities << "\n";
    out << "Inscricoes: " << stats.totalEnrollments << "\n";
    return out.str();
}

std::string ActivityTextReport::renderActivity(const Activity& activity, std::size_t index) const {
    std::ostringstream out;
    out << index + 1 << ". " << activity.name << "\n";
    out << "   Data/Horario: " << activity.date << " " << activity.time << "\n";
    out << "   Categoria: " << activity.category << "\n";
    out << "   Instrutor: " << activity.instructorUsername << "\n";
    out << "   Inscritos: " << activity.participants.size() << "\n";
    return out.str();
}

std::string ActivityTextReport::renderFooter(const UsageStats& stats) const {
    (void)stats;
    return "===============================\n";
}

std::string ActivityTextReport::separator() const {
    return "-------------------------------\n";
}
