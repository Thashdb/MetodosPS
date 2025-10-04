#include "ActivityHtmlReport.h"

#include <sstream>

std::string ActivityHtmlReport::renderHeader(const UsageStats& stats) const {
    std::ostringstream out;
    out << "<html><head><title>Relatorio de Atividades</title></head><body>";
    out << "<h1>Relatorio de Atividades</h1>";
    out << "<p>Total de usuarios: " << stats.totalUsers
        << " (" << stats.totalInstructors << " instrutores, "
        << stats.totalStudents << " alunos)</p>";
    out << "<p>Total de atividades: " << stats.totalActivities << "</p>";
    out << "<p>Total de inscricoes: " << stats.totalEnrollments << "</p>";
    out << "<table border=\"1\" cellspacing=\"0\" cellpadding=\"4\">";
    out << "<thead><tr><th>#</th><th>Nome</th><th>Data</th><th>Horario</th><th>Categoria</th><th>Instrutor</th><th>Inscritos</th></tr></thead><tbody>";
    return out.str();
}

std::string ActivityHtmlReport::renderActivity(const Activity& activity, std::size_t index) const {
    std::ostringstream out;
    out << "<tr>";
    out << "<td>" << (index + 1) << "</td>";
    out << "<td>" << activity.name << "</td>";
    out << "<td>" << activity.date << "</td>";
    out << "<td>" << activity.time << "</td>";
    out << "<td>" << activity.category << "</td>";
    out << "<td>" << activity.instructorUsername << "</td>";
    out << "<td>" << activity.participants.size() << "</td>";
    out << "</tr>";
    return out.str();
}

std::string ActivityHtmlReport::renderFooter(const UsageStats& stats) const {
    (void)stats;
    return "</tbody></table></body></html>";
}

std::string ActivityHtmlReport::separator() const {
    return "\n";
}
