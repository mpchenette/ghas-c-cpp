#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

void sqlInjectionExample(const char *userInput) {
    sqlite3 *db;
    char *errMsg = 0;
    int rc = sqlite3_open(":memory:", &db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return;
    }

    char sql[256];
    sprintf(sql, "SELECT * FROM users WHERE name = '%s';", userInput); // Potential SQL injection
    rc = sqlite3_exec(db, sql, 0, 0, &errMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }

    sqlite3_close(db);
}

int main() {
    sqlInjectionExample("'; DROP TABLE users; --");
    return 0;
}