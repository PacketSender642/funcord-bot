#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <orca/discord.h>
#include <orca/cee-utils.h>

#include "commands.c"

#include "events.c"

int main(int argc, char *argv[])
{


    log_info("Connecting..");

    const char *config_file;
    if (argc > 1)
        config_file = argv[1];
    else
        config_file = "./config.json";

    orca_global_init();
    struct discord *client = discord_config_init(config_file);
    assert(NULL != client && "Couldn't initialize client");

    // misc
    discord_set_on_command(client, "about", &on_about);
    discord_set_on_command(client, "ping", &on_ping);
    discord_set_on_command(client, "help", &on_help);
    // misc

    discord_set_on_ready(client, &on_ready);

    discord_run(client);

    discord_cleanup(client);
    orca_global_cleanup();
}