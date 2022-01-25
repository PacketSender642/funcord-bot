#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <orca/discord.h>

#include "commands.c"

void on_ready(struct discord *client)
{
    const struct discord_user *bot = discord_get_self(client);

    log_info("Succesfully connected to Discord as %s#%s!",
            bot->username, bot->discriminator);
    discord_set_presence(client, &(struct discord_presence_status){
                        .activities =
                        (struct discord_activity *[]){
                            &(struct discord_activity){
                            .name = "with you!",
                            .type = DISCORD_ACTIVITY_GAME,
                            .details = "Fixing some bugs",
                            },
                            NULL
                        },
                        .status = "idle",
                        .afk = false,
                        .since = discord_timestamp(client),
                    });
}



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

    discord_set_on_command(client, "about", &on_about);

    discord_set_on_ready(client, &on_ready);

    discord_run(client);

    discord_cleanup(client);
    orca_global_cleanup();
}