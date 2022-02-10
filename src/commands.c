void on_about(struct discord *client, const struct discord_message *msg) {
  if (msg->author->bot)
    return;

  struct discord_embed embed = {
      .title = "Funcord",
      .description = "A fun little bot!",
      .color = 3447003,
      .timestamp = discord_timestamp(client),
      .footer =
          &(struct discord_embed_footer){
              .text = "Made by Lilypad!",
          },
      .fields = (struct discord_embed_field *[]){
          &(struct discord_embed_field){
              .name = "<:arrowf:934873053358333982> Proudly made with C "
                      "<:arrowthere:934873053215735828>",
              .value = "We use [orca](https://github.com/cee-studio/orca) as "
                       "the discord library!",
          },
          &(struct discord_embed_field){
              .name = "<:arrowf:934873053358333982> We are also open source!"
                      "<:arrowthere:934873053215735828>",
              .value =
                  "hosted on "
                  "[github](https://github.com/PacketSender642/funcord-bot)",
          },
          &(struct discord_embed_field){
              .name = "<:bot_add_regular_icon_203030:934885898825379950>"
                      " Want to add me?",
              .value =
                  "[Here](https://discord.com/api/oauth2/authorize?client_id=933346229151207554&permissions=8&scope=bot\%20applications.commands) for admin perms "
                  "and [here](https://discord.com/api/oauth2/authorize?client_id=933346229151207554&permissions=124992&scope=bot\%20applications.commands) for basic stuff.",
          },
          NULL}};

  struct discord_create_message_params params = {.embed = &embed};
  discord_create_message(client, msg->channel_id, &params, NULL);
}

void on_ping(struct discord *client, const struct discord_message *msg) {
  if (msg->author->bot)
    return;

	int ping = discord_get_ping(client);

	char str[10];

  sprintf(str, "%dms", ping);

  struct discord_embed embed = {
    .title = "Ping pong",
    .description = str,
    .color = 3447003,
    .timestamp = discord_timestamp(client),
  };

	struct discord_create_message_params params = {.embed = &embed};
	discord_create_message(client, msg->channel_id, &params, NULL);
}

void on_help(struct discord *client, const struct discord_message *msg) {
  if (msg->author->bot)
    return;

	int ping = discord_get_ping(client);

	char str[10];

  sprintf(str, "%dms", ping);

  struct discord_embed embed = {
      .title = "Funcord - Help",
      .description = "funny discord bot",
      .color = 3447003,
      .timestamp = discord_timestamp(client),
      .footer =
          &(struct discord_embed_footer){
              .text = "Checkout f/about",
          },
      .fields = (struct discord_embed_field *[]){
          &(struct discord_embed_field){
              .name = "<:arrowf:934873053358333982> RPG Commands"
                      "<:arrowthere:934873053215735828>",
              .value = "Soon",
          },
          &(struct discord_embed_field){
              .name = "<:arrowf:934873053358333982> Mod Commands"
                      "<:arrowthere:934873053215735828>",
              .value =
                  "Soon",
          },
          &(struct discord_embed_field){
              .name = "<:arrowf:934873053358333982> Misc Commands"
                      "<:arrowthere:934873053215735828>",
              .value =
                  "`about`, `help`, `ping`",
          },
          NULL}};

	struct discord_create_message_params params = {.embed = &embed};
	discord_create_message(client, msg->channel_id, &params, NULL);
}