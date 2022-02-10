void on_ready(struct discord *client)
{
    const struct discord_user *bot = discord_get_self(client);

    log_info("Succesfully connected to Discord as %s#%s!",
            bot->username, bot->discriminator);
    discord_set_presence(client, &(struct discord_presence_status){
                        .activities =
                        (struct discord_activity *[]){
                            &(struct discord_activity){
                            .name = "with you! | Creating segfaults",
                            .type = DISCORD_ACTIVITY_GAME,
                            .details = "Bug fixing",
                            },
                            NULL
                        },
                        .status = "idle",
                        .afk = false,
                        .since = discord_timestamp(client),
                    });
}
