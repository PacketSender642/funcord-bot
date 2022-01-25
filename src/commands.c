void on_static(struct discord *client, const struct discord_message *msg)
{
    if (msg->author->bot) return;

    struct discord_embed embed = {
        .title = "Funcord",
        .description = "A fun little bot!",
        .color = 3447003,
        .timestamp = discord_timestamp(client),
        .footer =
        &(struct discord_embed_footer){
            .text = "Made by Lilypad!",
        },
    };

    struct discord_create_message_params params = { .embed = &embed };
    discord_create_message(client, msg->channel_id, &params, NULL);
}